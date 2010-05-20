class MotorCycle  
  def initialize(make, color)  
    # Instance variables  
    @make = make  
    @color = color  
    end  
  def startEngine  
    if (@engineState)  
      puts 'Engine Running'  
    else  
      @engineState = true  
      puts 'Engine Idle'  
    end  
  end  
end  