--
-- rotate_string.hs
-- RotateString
--
-- Created by Muhammad Hussein Nasrollahpour on 6/22/14
-- Copyright (c) 2014 Chocolate. All rights reserved.
--

import Data.List
import Control.Monad

rotate :: String -> String
rotate st = intercalate " " (tail (zipWith (++) (tails st) (inits st)))

main = do
   n <- readLn :: IO Int
   inputdata <- getContents

   mapM putStrLn . map rotate . lines $ inputdata
