class Exercicio11{
   int x, y, energia;
   public static void main(String []args){
      Exercicio11 exercicio11 = new Exercicio11();

      exercicio11.x = 1;
      exercicio11.y = 1;
      exercicio11.energia = 1;

      exercicio11.mover(1,2);
      System.out.println(exercicio11.x);
      System.out.println(exercicio11.y);
      exercicio11.abastecer(10);
   }

   void mover(int dx, int dy){
      x += dx;
      y += dy;
   }

   void abastecer(int c){
      System.out.println(energia += c);
   }
}
