require 'test/unit'
require_relative "./two_refactor"

class SolutionTest < Test::Unit::TestCase
  def test_locations_base_example
    locations = [7,3,7,3,1,3,4,1]
    assert_equal(Solution.new(locations).solve!, 5)
  end

  def test_locations_at_the_end
    locations = [7,3,7,3,3,4,7,3,7,3,1,7,3,1,4]
    assert_equal(Solution.new(locations).solve!, 4)
  end

  def test_locations_at_the_beginning
    locations = [7,3,1,4,7,3,3,4,7,3,7,3,1,7,3,1]
    assert_equal(Solution.new(locations).solve!, 4)
  end

  def test_locations_sparse
    locations = [7,3,4,7,3,3,4,7,3,7,3,1,7,3,1]
    assert_equal(Solution.new(locations).solve!, 6)
  end

  def test_empty_list
    locations = []
    assert_equal(Solution.new(locations).solve!, -1)
  end
end
