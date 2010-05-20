require File.expand_path(File.dirname(__FILE__) + '/challenge')

describe Challenge do
  before :each  do
    @challenge = Challenge.new(Math.exp 1)
  end

  it 'should return an array of correct indexes' do
    @challenge.idx(@challenge.e, [27,1,8,82]).should eql([0,2,3,7])
    @challenge.idx(@challenge.e, [71,1,2]).should eql([1,6,8])
  end

  it 'should return the sum of an array' do
    @challenge.sum([1,7,9]).should eql(17)
    @challenge.sum([37,5]).should eql(42)
  end

  it 'should return a the correct sliced array' do
    @challenge.slice(0,2,[1,4,7,10,13,16,19]).should eql([1,4,7])
    @challenge.slice(2,4,[1,4,7,10,13,16,19]).should eql([7,10,13])
  end

  it 'should return the fibonacci sequence until some number' do
    @challenge.fib_number(1).should eql(1)
    @challenge.fib_number(2).should eql(1)
    @challenge.fib_number(5).should eql(5)
    @challenge.fib_number(7).should eql(13)
  end

  it 'should have the populate fibonacci sequence' do
    @challenge.populate_fib_until(7)
    @challenge.fib.should eql([0,1,1,2,3,5,8])
  end

  it 'should return an answer of the challenge' do
    @challenge.show_answer.should match(/A = \d/)
  end
end
