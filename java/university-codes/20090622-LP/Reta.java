class Reta{
   Ponto p1;
   Ponto p2;

   void defReta(double a, double b, double c, double d){
      p1 = new Ponto();
      p2 = new Ponto();
      p1.defCoordenadas(a,b);
      p2.defCoordenadas(c,d);
      p1.defDescricao("Inicio");
      p2.defDescricao("Final");
   }

   void mostrarReta(){
      System.out.println("Pontos que definem a reta: ");
      p1.mostrarPonto();
      p2.mostrarPonto();
   }

   double distancia(){
      double dx, dy;
      dx = p1.x - p2.x;
      dy = p1.y - p2.y;
      double d;
      d = Math.sqrt(dx*dx + dy*dy);
      return d;
   }

   public static void main(String []args){
      System.out.println("Inicio do programa");
      System.out.println("Fim do programa");
   }
}
