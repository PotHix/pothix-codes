class Disciplina{
  String nome;
  int horas;
  void info(){
    System.out.println("Disciplina " + nome);
    System.out.println("Carga: " + horas + " horas\n");
  }
}

class Exemplo1{
  public static void main(String[] args){
    Disciplina x = new Disciplina();
    x.nome = "ED";
    x.horas = 220;
    Disciplina y = new Disciplina();
    y.nome = "LPII";
    y.horas = 110;
    y=x;
    y.horas = 330;
    x.info();
    y.info();
  }
}

