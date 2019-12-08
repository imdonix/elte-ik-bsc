data Month = Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec
type Year = Int

numberOfDays :: Year -> Month -> Int
numberOfDays y Feb 
    | (mod y 4 == 0 && mod y 100 /= 0) || mod y 400 == 0 = 29
    | True = 28
numberOfDays _ Jan = 31
numberOfDays _ Mar = 31
numberOfDays _ Apr = 30
numberOfDays _ May = 31
numberOfDays _ Jun = 30
numberOfDays _ Jul = 31
numberOfDays _ Aug = 31
numberOfDays _ Sep = 30
numberOfDays _ Oct = 31
numberOfDays _ Nov = 30
numberOfDays _ Dec = 31