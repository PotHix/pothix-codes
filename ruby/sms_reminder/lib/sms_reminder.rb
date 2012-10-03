require 'rubygems'
require 'open-uri'
require 'uri'
require 'date'
require 'json'
require 'yaml'
require 'googlecalendar'

class SmsReminder
  include Googlecalendar

  def initialize
    configs = YAML::load(File.read(File.expand_path(File.dirname(__FILE__) + '/../config/sms_reminder.yml')))
    @calendar_config = {
      :name     => configs['sms_reminder']['calendar']['name'],
      :username => configs['sms_reminder']['calendar']['username'],
      :password => configs['sms_reminder']['calendar']['password'],
      :calendar => configs['sms_reminder']['calendar']['calendar']
    }

    @default_reminder = configs['sms_reminder']['default_config']['reminder']
  end

  def request_content content
    open(URI::escape(content)).read
  end

  def default_reminder
    @default_reminder
  end
  
  # post a google calendar event with sms reminder
  # options should be = {
  #   :title => 'event title',
  #   :message => 'event body'
  # }
  def post_reminder(reminder_minutes, date = Time.now, options={})
    formatted_date = date.strftime('%Y-%m-%dT%H:%M:%S.000Z')  

    calendar_instance = GData.new
    calendar_instance.login(@calendar_config[:username], @calendar_config[:password])
    event = {
      :title     => options[:title],
      :content   => options[:message],
      :author    => @calendar_config[:name],
      :email     => @calendar_config[:username], 
      :where     => self.class.to_s.gsub('Reminder',''), 
      :startTime => formatted_date,
      :endTime   => formatted_date
    }
    calendar_instance.add_reminder(event, reminder_minutes.to_s, 'sms')
    calendar_instance.new_event(event)
  end
end
