class MorseConverter
HASH_MORSE = {
  '.-' => 'a',
  '-...' => 'b',
  '-.-.' => 'c',
  '-..' => 'd',
  '.' => 'e',
  '..-.' => 'f',
  '--.' => 'g',
  '....' => 'h',
  '..' => 'i',
  '.---' => 'j',
  '-.-' => 'k',
  '.-..' => 'l',
  '--' => 'm',
  '-.' => 'n',
  '---' => 'o',
  '.--.' => 'p',
  '--.-' => 'q',
  '.-.' => 'r',
  '...' => 's',
  '-' => 't',
  '..-' => 'u',
  '...-' => 'v',
  '.--' => 'w',
  '-..-' => 'x',
  '-.--' => 'y',
  '--..' => 'z',
  '.----' => '1',
  '..---' => '2',
  '...--' => '3',
  '....-' => '4',
  '.....' => '5',
  '-....' => '6',
  '--...' => '7',
  '---..' => '8',
  '----.' => '9',
  '-----' => '0',
  '/' => ' ', # Mapping foward bar to be a space
  '-..-.' => '/',
  '.-.-.' => '+',
  '-...-' => '=',
  '.-.-.-' => '.',
  '--..--' => ',',
  '..--..' => '?',
  '-.--.' => '(',
  '-.--.-' => ')',
  '-....-' => '-',
  '.-..-.' => '"',
  '..--.-' => '_',
  '.----.' => "'",
  '---...' => ':',
  '-.-.-.' => ';',
  '...-..-' => '$' 
}

  def to_plain(string_morse)
    @translated_string = ''
    translate(string_morse)
  end

  def to_morse(string)
    string.split('').map { |c| HASH_MORSE.key c.downcase }.join(' ')
  end

  private
  def translate(string_morse)
    array_morse = string_morse.split
    array_morse.each { |morse| @translated_string << HASH_MORSE[morse] if HASH_MORSE[morse] }
    @translated_string
  end
  
  # Syntactic sugar for converting single words to morse code
  def method_missing(symbol)
    to_morse(symbol.to_s)
  end
end

