#!/usr/bin/ruby -w 

# require 'sftpc'
require 'getoptlong'

########################################################
# h. Add Validation.
# Call using "ruby tsftpc.rb -hftp.ibiblio.org -n21 -uanonymous -ps@s.com"
# The parameters can be in any order.
# g. usage: ruby ftp_client.rb ft_site_url port_no username password
#     -- Handle Arguments passed to the program (ARGV, ...) 
#     -- Print Usage if arguments are not fully "recognizable" - there's no server name or
#         IP number or no username or no password or ... 

def print_usage
  STDERR.puts <<-FIN
Usage: ruby #{$0} -h ftp.ibiblio.org -n 21 [ -u anonymous [ -p s@s.com ] ]
Can put arguments in any order. 
Note that username and password are optional.
FIN
  exit!(1)
end

unless (2..8) === ARGV.length
  print_usage
end

host_name = port_no = user_name = password = ""
port_no = 21 # Default value.
user_name = "anonymous" # Default value.
password = "anonymous@mail.com" # Default value.

# Specify the options we accept and initialize the option parser.
opts = GetoptLong.new(
[ '--help', '-?', GetoptLong::NO_ARGUMENT ],
[ "-h", GetoptLong::REQUIRED_ARGUMENT ],
[ "-n", GetoptLong::REQUIRED_ARGUMENT ],
[ "-u", GetoptLong::REQUIRED_ARGUMENT ],
[ "-p", GetoptLong::REQUIRED_ARGUMENT ]
)

# process the parsed options
opts.each do |opt, arg|
  case opt
    when '-h'
      host_name = arg
    when '-n'
      port_no = arg
    when '-u'
      user_name = arg
    when '-p'
      password = arg
    else
      print_usage
    end
end
#puts host_name
#puts port_no
#puts user_name
#puts password
#END OF OTHERS' CODE.

#####################################################
class SImpleFTPClient 
  
  # something about "If a block is given, it is passed the SimpleFTPClient object, 
  # which will be closed when the block finishes, or when an exception is raised.

  attr_reader :hostname, :port_no, :user_name, :password
  def initialize(host_name, port_no, user_name, password)
    @hostname = host_name
    @port_no = port_no
    @user_name = user_name
    @password = password
    #puts @hostname
    #puts @port_no
    #puts @user_name
    #puts @password
    validate_url
  end

  def close
    # Close something.
  end

  def self.open *args
    begin
      session = SimpleFTPClient.new args
      if block_given?
        yield session
        session.close
      else
        session
      end
    rescue
      session.close
    end
  end

  # Validate url (only integers and periods ##.##.##.##)
  def validate_url
    url = @hostname
    #puts "DEBUG: url: " + url
  
    url_part = []
    url_parts = url.split('.') 
    #puts "DEBUG: url_parts[0]: " + url_parts[0]
  
    if url_parts[0].is_a? Numeric  
      validate_sub_url(url_parts[0])
      validate_sub_url(url_parts[1])
      validate_sub_url(url_parts[2])
      validate_sub_url(url_parts[3])
    else # letters
      #puts "URL just letters"
    end
    ping_url
  end
  
  def validate_sub_url(sub_url)
    if (sub_url.to_i < 0) and (sub_url.to_i >= 255)
      puts "URL [" + sub_url.to_s + "] outside the accepted range"
    else
      puts "URL [" + sub_url.to_s + "] insidee the accepted range"
    end
  end
  
  def ping_url
    system("ping " + @hostname.to_s)
  end
end # class

theargs = SImpleFTPClient.new(host_name, port_no, user_name, password)

########################################################
# a. RFC 959 (Get copy and read => "FTP Specs" forum)
# 
# b. TCPSocket (week 13)
#
# c. Use ftp.ibiblio.org to test this program.
#
# d. ftp_client.rb shall use these:
#    -- USER anonymous
#    -- PASS your_email_id
#    -- list: SYST, FEAT, PWD, TYPE I, PASV, LIST, QUIT
#
# e. Write program after learning Sockets.
#
# i. Add exception handling.
#
# j. Prompt for password and DO NOT ECHO password.
#
# k. Parse the arguments and "simulate" a file transfer of: 
#    -- one file only 
#     -- one folder only 
#     -- several files matching a pattern (mask) 
#     -- one folder and it's sub-folders, with all filenames. 
#     -- one folder and it's sub-folders, with all filenames matching a pattern. 
#EOF