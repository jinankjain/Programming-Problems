import Data.List
import Control.Monad

rotate :: String -> String
rotate st = intercalate " " (tail (zipWith (++) (tails st) (inits st)))

main = do
   n <- readLn :: IO Int
   inputdata <- getContents 
   
   mapM putStrLn . map rotate . lines $ inputdata
