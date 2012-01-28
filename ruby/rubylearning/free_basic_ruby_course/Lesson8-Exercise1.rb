require "date"
def month_days(m,y=Date.today.year)
  if (1..12) === m and y > 0 then #validating: no negative year and months between 0 and 12
    #puts arr = [1,3,5,7,8,10,12].include?(m) ? "31" : m==2 ? ((Date.new(y,m) >> 1) -1).day : "30" #trying to do in one line
    puts "This month have #{((Date.new(y,m) >> 1) -1).day} days" #Really this is the short code! Tks Satoshi!
  else
    puts "Invalid Month or Year!"
  end
end

#testing
month_days(4)
month_days(2,1988)