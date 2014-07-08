--
-- multiply_3_5.hs
-- Multiply35
--
-- Created by Muhammad Hussein Nasrollahpour on 7/8/14
-- Copyright (c) 2014 Chocolate. All rights reserved.
--


is_mul_3_5 x = (0 == x `mod` 3) || (0 == x `mod` 5)
sum' x = sum (filter is_mul_3_5 [1..(x-1)])

main = do
    n <- readLn :: IO Int
    inputData <- getContents
    
    mapM_ print $ map (sum' . (read :: String -> Int)) $ lines inputData
