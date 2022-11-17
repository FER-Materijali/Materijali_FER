module ML (
  load, feats, mean, cov, var, randrows,
  replicateM, fromRows, sub, det) where

import Data.Packed
import Numeric.Container
import Numeric.LinearAlgebra.Algorithms (det)
import Data.List (foldl1')
import System.Random (newStdGen, randomRs)
import Control.Monad (replicateM)

type M = Matrix Double
type V = Vector Double

-- Učitamo defaultnu silhouttes.txt matricu, pritom mičući prvi redak s imenima
-- stupaca i zadnji stupac s klasom primjera, jer su nam nepotrebni.
load :: IO M
load = do
  ls <- (tail . lines) `fmap` readFile "silhouettes.txt"
  return . fromLists $ map (map read . init . words) ls

-- Dohvati samo određene stupce/značajke matrice.
feats :: [Int] -> M -> M
feats cs = trans . extractRows cs . trans

-- Procjena vektora srednje vrijednosti.
mean :: M -> V
mean m = scale (1/n) . foldl1' add $ toRows m
  where
    n = fromIntegral $ rows m

-- Procjena kovarijacijske matrice.
cov :: M -> M
cov m = scale (1/n) $ trans x <> x
  where
    x = m `sub` repmat (asRow $ mean m) (rows m) 1
    n = fromIntegral $ rows m

-- Varijancu dohvaćamo putem dijagonale kovarijacijske matrice.
var :: M -> V
var = takeDiag . cov

-- Nasumično izdvoji n redaka matrice.
randrows :: Int -> M -> IO M
randrows n m = do
  rs <- (take n . randomRs (0, rows m - 1)) `fmap` newStdGen
  return $ extractRows rs m
