rack_app = lambda do |env|
  [
    200,
    {"Content-Type" => "text/plain"},
    ["Command line argument you typed was: #{ARGV.join(" ")}"]
  ]
end
puts rack_app.call({})
