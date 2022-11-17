module Bayes where

import ML
import Data.Packed
import Numeric.Container
import Data.List (findIndex, foldl', sort)
import Control.Monad (forM_)
import Text.Printf (printf)
import qualified Data.Map.Strict as M
import Debug.Trace (trace)

type FeatPos = Int
type FeatValue = String
type FeatDesc = [FeatValue]

carFeats :: [FeatDesc]
carFeats = map words [
  "vhigh high med low",
  "vhigh high med low",
  "2 3 4 5more",
  "2 4 more",
  "small med big",
  "low med high",
  "unacc acc good vgood"]

movieFeats :: [FeatDesc]
movieFeats = map words [
  "svemir Zemlja drugdje",
  "znanstvenica dijete kriminalac policajac",
  "prošlost budućnost sadašnjost",
  "da ne",
  "da ne"]

-- Učitava dataset s diskretnim vrijednostima, no svaku zamjenjuje brojem.
loadDiscrete :: [FeatDesc] -> FilePath -> IO M
loadDiscrete fs path = do
  ls <- (tail . lines) `fmap` readFile path
  return . fromLists $ map (zipWith toNum fs . words) ls

toNum :: FeatDesc -> FeatValue -> Double
toNum f v = case findIndex (==v) f of
  Just i -> fromIntegral i
  Nothing -> error $ "Bad feat description? " ++ show f

fromNum :: FeatDesc -> Double -> FeatValue
fromNum fd i = fd !! round i

fromNums :: [FeatDesc] -> [Double] -> [FeatValue]
fromNums = zipWith fromNum

unload :: Dataset -> [[String]]
unload (Dataset fs xs _ _) = map (fromNums fs) $ toLists xs

data Dataset = Dataset {
  featdesc :: [FeatDesc],
  examples :: M,
  params :: M.Map Double Double, -- P(y = key) = val
  conds  :: M.Map (FeatPos, Double, Double) Double -- Uvjetna..
} deriving (Show)

loadDataset_ :: Double -> FilePath -> [FeatDesc] -> IO Dataset
loadDataset_ l path fs = do
  d <- loadDiscrete fs path
  let max = cols d - 1

  -- P(C_j) = ?
  let yDim = fromIntegral $ length (last fs) :: Double
  let ys = [0.0 .. yDim - 1] :: [Double]
  let rs = map (p_ l fs d max) ys :: [Double]
  let pmap = M.fromList $ zip ys rs :: M.Map Double Double

  -- Sve uvjetne.
  let combs = [(i, v, y) | i <- [0 .. max - 1] :: [FeatPos],
               v <- [0.0 .. fromIntegral $ length (fs !! i) - 1] :: [Double],
               y <- ys]

  let pars = map (\(i, v, y) ->
                   let y' = fromNum (last fs) y
                   in  pWith_ l fs d i v [(max, y')]) combs

  let condmap = M.fromList $ zip combs pars
  return $ Dataset fs d pmap condmap

loadDataset = loadDataset_ 0.0
loadDataset' = loadDataset_ 1.0

p_ :: Double -> [FeatDesc] -> M -> FeatPos -> Double -> Double
p_ lambda fs xs i numV =
  (matched + lambda) / (fromIntegral (rows xs) + featDim * lambda)
  where
    featDim = fromIntegral . length $ fs !! i
    isMatch xval = if xval == numV then 1.0 else 0.0
    matched = sumElements . mapVector isMatch $ toColumns xs !! i

-- Stvori dataset koji sadrži svaki primjer koji na FeatPos ima FeatValue.
constrain :: [FeatDesc] -> M -> FeatPos -> FeatValue -> M
constrain fs xs i v = xs'
  where
    xs' = fromRows . filter isMatch $ toRows xs
    Just numV = fromIntegral `fmap` (findIndex (==v) $ fs !! i)
    isMatch vect = vect @> i == numV

pWith_ :: Double -> [FeatDesc] -> M -> FeatPos -> Double ->
          [(FeatPos, FeatValue)] -> Double
pWith_ lambda fs xs i v cs = p_ lambda fs xs'' i v
  where
    xs'' = foldl' (\xs' (i', v') -> constrain fs xs' i' v') xs cs

pWith :: Dataset -> FeatPos -> Double -> [(FeatPos, FeatValue)] -> Double
pWith (Dataset fs _ _ conds) i v cs = foldl' f 1.0 cs
  where
    f p (i', v') = p * conds M.! (i, v, toNum (last fs) v')

naive :: Dataset -> [FeatValue] -> [(Double, FeatValue)]
naive d@(Dataset fs xs ps conds) xStr =
  reverse . sort . zipWith (\i v -> (prob i, v)) [0.0..] $ last fs
  where
    x :: [Double]
    x = zipWith toNum fs xStr

    -- Uz y = Double, kakva je vjerojatnost x?
    prob :: Double -> Double
    prob y =
      let cs = zipWith (\i v -> conds M.! (i, v, y)) [0..] x
      in  product cs * ps M.! y


trace' a = trace (show a) a

lfunc :: Eq a => a -> a -> Double
lfunc x y = if x /= y then 1.0 else 0.0

-- Izračunaj empirijsku i pogrešku generalizacije na temelju dva skupa.
zadatakAIV :: IO ()
zadatakAIV = do
  train <- loadDataset "CarEvaluation-train.txt" carFeats
  test  <- loadDataset "CarEvaluation-test.txt"  carFeats

  -- | Prvo klasificiramo primjere iz seta za učenje.
  let ys = map last $ unload train -- Stvarni y.
  let ys' = map (snd . head . naive train . init) $ unload train -- Predviđeni.

  let count = fromIntegral $ length ys
  let ediff = sum (zipWith lfunc ys ys') / count -- Empirijska pogreška.
  printf "Empirijska pogreška je %f.\n" ediff

  -- | Zatim klasificiramo one iz seta za provjeru.
  let ys = map last $ unload test
  let ys' = map (snd . head . naive train . init) $ unload test

  let count = fromIntegral $ length ys
  let gdiff = sum (zipWith lfunc ys ys') / count -- Generalizacije.
  printf "Pogreška generalizacije je %f.\n" gdiff


{-  OLD CODE, PRE-ReWRITE
-- Ispiši Latex tablicu parametara naivnog modela.
zadatakAI :: IO ()
zadatakAI = do
  d <- loadDataset "CarEvaluation2.txt" carFeats
  let half = M.size (conds d) `div` 2
  let tests = M.keys $ conds d
  let (t1, t2) = (take half tests, drop half tests)
  forM_ (zip t1 t2) $ \((i, v, y), (i', v', y')) -> do
    let res = pWith d i v [(6, y)]
    let res' = pWith d i' v' [(6, y')]
    let form = "P(x_%d=\\text{%s}|y=\\text{%s})&=%.3f &\
               \P(x_%d=\\text{%s}|y=\\text{%s})&=%.3f\\\\\n"
    printf form i v y res i' v' y' res'
-}

{- OLD CODE, PRE-ReWRITE
-- Ispiši Latex tablicu parametara naivnog modela, ali sa zaglađivanjem.
zadatakAIII :: IO ()
zadatakAIII = do
  d <- loadDataset "CarEvaluation2.txt" carFeats
  let tests = sort [(y, (i, v)) | (i, pos) <- zip [0..5] carFeats, v <- pos,
                                   y <- last carFeats]
  let half = length tests `div` 2
  let (t1, t2) = (take half tests, drop half tests)
  forM_ (zip t1 t2) $ \((y, (i, v)), (y', (i', v'))) -> do
    let res = pWith' d i v [(6, y)]
    let res' = pWith' d i' v' [(6, y')]
    let form = "P(x_%d=\\text{%s}|y=\\text{%s})&=%.3f &\
               \P(x_%d=\\text{%s}|y=\\text{%s})&=%.3f\\\\\n"
    printf form i v y res i' v' y' res'
-}
