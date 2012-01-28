# String#eql?, tests two strings for identical content.  
# It returns the same result as ==  
# String#equal?, tests whether two strings are the same object  
s1 = 'Jonathan'  
s2 = 'Jonathan'  
s3 = s1  
if s1 == s2  
	puts 'Both Strings have identical content'  
else  
	puts 'Both Strings do not have identical content'  
end  

if s1.eql?(s2)  
	puts 'Both Strings have identical content'  
else  
	puts 'Both Strings do not have identical content'  
end  

if s1.equal?(s2)  
	puts 'Two Strings are identical objects'  
else  
	puts 'Two Strings are not identical objects'  
  puts s1.id
  puts s2.id
  puts s3.id
end  

if s1.equal?(s3)  
	puts 'Two Strings are identical objects'  
else  
	puts 'Two Strings are not identical objects'  
end  