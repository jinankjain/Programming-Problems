expandList :: [Int] -> [Int]
r t e = replicate t e
expandList [] = []
expandList (x:xs) = r x x ++ expandList xs 

main :: IO ()
main = getLine >>= print. expandList. read

