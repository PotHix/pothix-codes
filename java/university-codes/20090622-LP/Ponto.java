class Ponto{
   String descricao;
   double x, y;
   void defCoordenadas(double a, double b){
      x = a;
      y = b;
   }

   void defDescricao(String s){
      descricao = s;
   }

   void mostrarPonto(){
      System.out.println(descricao);
      System.out.println("x = " + x);
      System.out.println("y = " + y);
   }
}
