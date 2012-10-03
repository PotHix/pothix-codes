class GooglonWord
  FOO_TYPE_LETTERS = "hcdxn"
  ALPHABET = %w(m n t w f j z p g h r b v l s d k q c x)

  include Comparable

  attr_accessor :word, :custom_unique_id

  def initialize(googlon_string)
    @word = googlon_string
  end

  def preposition?
    word.size == 3 &&
    FOO_TYPE_LETTERS.include?(word[-1]) &&
    !word.include?("g")
  end

  def verb?
    word.size >= 6 &&
    !FOO_TYPE_LETTERS.include?(word[-1])
  end

  def first_person_verb?
    word.size >= 6 &&
    FOO_TYPE_LETTERS.include?(word[0]) &&
    !FOO_TYPE_LETTERS.include?(word[-1])
  end

  def to_sort_number
    total_number = ""
    word.each_byte do |byte|
      number = ""
      number << ALPHABET.index(byte.chr).to_s
      number = "0" + number if number.size == 1
      total_number << number
    end

    while total_number.size < 20 do
      total_number << "0"
    end

    total_number.to_i
  end

  def to_i
    index, number = 0, 0
    word.each_byte do |letter|
      if index.zero?
        number = ALPHABET.index(letter.chr)
      else
        number += ALPHABET.index(letter.chr)*20**index
      end
      index+=1
    end
    number
  end

  def beautiful_number?
    number = self.to_i
    (number >= 516702) && (number % 4 == 0)
  end

  def to_s
    word
  end

  def <=>(text)
    self.to_sort_number <=> text.to_sort_number
  end
end

class GDD
  attr_accessor :text

  def initialize(text)
    @text = text.split(" ").map do |word|
      GooglonWord.new(word)
    end
  end

  def find_prepositions
    text.select &:preposition?
  end

  def find_verbs
    text.select &:verb?
  end

  def find_first_person_verbs
    text.select &:first_person_verb?
  end

  def find_beautiful_numbers
    text.map {|word| word.to_s if word.beautiful_number? }.compact.uniq
  end

  def sort_and_strip_repetitions
    text.sort.map{|word| word.to_s}.uniq.join(" ")
  end
end
