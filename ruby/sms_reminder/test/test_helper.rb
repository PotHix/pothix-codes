require File.expand_path(File.dirname(__FILE__) + '/../lib/sms_reminder')
require File.expand_path(File.dirname(__FILE__) + '/../lib/todoist_reminder')

require 'test/unit'
require 'webmock' 

include WebMock
