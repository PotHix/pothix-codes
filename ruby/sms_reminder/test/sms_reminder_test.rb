require File.expand_path(File.dirname(__FILE__) + '/test_helper')

class SmsReminderTest < Test::Unit::TestCase
  def setup
    @sms_reminder = SmsReminder.new
  end
  
  def test_default_reminder
    default_reminder_file = YAML::load(File.read(File.expand_path(File.dirname(__FILE__) + '/../config/sms_reminder.yml')))
    assert_equal(@sms_reminder.default_reminder, default_reminder_file['sms_reminder']['default_config']['reminder'])
  end
end
