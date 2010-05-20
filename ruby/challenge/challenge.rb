class Challenge
  attr_accessor :fib, :e

  def initialize e
    @fib = []
    @e = e
  end

  def idx(e, array_numbers = [])
    indexes = []
    valid_indexes = []

    numbers = e.to_s.gsub('.','')
    array_numbers.each do |array_number|
      num = array_number.to_s

      numbers.size.times do |index|
        if numbers.slice(index,num.size) == num && valid_indexes[index].nil? && index >= valid_indexes.size
          mark_as_used(valid_indexes, index, num.size)
          indexes.push(index)
          break
        end
      end
    end

    indexes
  end

  def sum(array_numbers = [])
    array_numbers.inject do |sum, num|
      sum + num
    end
  end

  def fib_number(n)
    return n.abs if n < 1
    fib_number(n-1)+fib_number(n-2)
  end

  def populate_fib_until(number)
    number.times do |n|
      @fib << fib_number(n)
    end
  end

  def slice(initial, final, array_numbers = [])
    sliced_array = []
    array_numbers.each_with_index do |array_number, index|
      sliced_array.push(array_number) if index <= final && index >= initial
    end
    sliced_array
  end

  def show_answer
    populate_fib_until 26
    "A = #{sum(idx(self.e,slice(0,24,fib)))}"
  end

  private
    def mark_as_used(valid_indexes, index, size)
      size.times do |n|
        valid_indexes[index+n] = 1
      end
    end
end
