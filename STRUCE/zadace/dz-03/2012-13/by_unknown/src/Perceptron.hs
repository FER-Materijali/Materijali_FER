module Perceptron where

import Control.Monad (foldM)

type Example = (Double, Double, Double)
type Weights = (Double, Double, Double)

examples :: [Example]
examples = [
  (-3, 1, 1),
  (-3, 3, 1),
  ( 1, 2, -1),
  ( 2, 1, -1)]

run :: IO ()
run = loop (0, 0, 0)

loop :: Weights -> IO ()
loop w = do
  w' <- foldM update w examples
  if w /= w' then
    loop w'
  else do
    putStrLn $ "Konačan W: " ++ show w'

ni :: Double
ni = 0.005

x0 :: Double
x0 = 1

f :: Weights -> Example -> Double
f (w0, w1, w2) (x1, x2, _)
  | w0 + w1*x1 + w2*x2 >= 0 = 1
  | otherwise = -1
  
update :: Weights -> Example -> IO Weights
update w@(w0, w1, w2) x@(x1, x2, y) = do
  putStrLn $ "Novi korak za: " ++ show x
  if f w x /= y then do
    let c@[c0, c1, c2] = map (\v -> v*ni*y) [x0, x1, x2]
    putStrLn $ "Korekcija: " ++ show c
    let w' = (w0+c0, w1+c1, w2+c2)
    putStrLn $ "Novi W: " ++ show w'
    return w'
  else do
    putStrLn "Ispravno klasificiran, nema korekcije."
    return w