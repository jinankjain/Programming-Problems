--
-- expand_list.hs
-- ExpandList
-- Created by Muhammad Hussein Nasrollahpour on 6/21/14
-- Copyright (c) 2014 Chocolate. All rights reserved.
--

expandList :: [Int] -> [Int]
r t e = replicate t e
expandList [] = []
expandList (x:xs) = r x x ++ expandList xs 

main :: IO ()
main = getLine >>= print. expandList. read

