class Bkp
  def initialize(linkBkp)
    @linkBKP = linkBkp
    require('FileUtils')
    criaDir
  end
  
  def criaDir
    nomeDaPasta = Date.today.to_s
    Dir.mkdir @linkBKP + nomeDaPasta #Cria o primeiro sub-diretório
    Dir.chdir @linkBKP + nomeDaPasta #Cria o segundo sub-diretório
  end
  
  def copiaArq(from,to)
    #FileUtils.cp_r 'c:/logs/.', '\\Color\backups'
    FileUtils.cp_r from + '/.', to  #Copia os arquivos da Color Plus
  end
end

bkp = Bkp.new('C:/Documents and Settings/PotHix/Desktop/')
bkp.copiaArq('D:/arquivos CP','Arquivos CP')
bkp.copiaArq('C:/Inetpub/wwwroot/Desenvolv','Desenvolv')
