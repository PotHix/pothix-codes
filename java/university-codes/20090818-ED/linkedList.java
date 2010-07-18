class TestLLSL{
   public static void main(String[] args){
      Celula inicio;
      CLLSL lista = new CLLSL();
      Celula novaCelula = new Celula();
      inicio = lista.incluiInicioLLSL(novaCelula);
      inicio = lista.excluiInicioLLSL(inicio);
   }
}

class Celula{
   Object info;
   Celula prox;
}

class CLLSL{
   Celula pInicio;

   CLLSL(){
      pInicio = null;
   }

   public Celula incluiInicioLLSL(Object x){
      Celula pNovo = new Celula();
      pNovo.info = x;
      pNovo.prox = pInicio;

      return pNovo;
   }

   public Celula excluiInicioLLSL(Celula pInicio){
      Celula novoInicio = pInicio.prox;
      pInicio = null;
      return novoInicio;
   }
}
