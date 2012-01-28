# p070rubysmtp.rb  
require 'net/smtp'  
user_from = "superman@world.com"  
user_to = "willian.molinari@gmail.com"#"batman@world.com"  
the_email = "From: superman@world.com\nSubject: Hello\n\nEmail by Ruby in Pune.\n\n"  
# handling exceptions  
begin  
  Net::SMTP.start('localhost', 25) do |smtpclient|  
    smtpclient.send_message(the_email, user_from, user_to)  
  end  
rescue Exception => e  
  print "Exception occured: " + e  
end