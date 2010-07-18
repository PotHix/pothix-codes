class Celula{
   Object info;
   Celula prox;
}

class CLLSL{
   Celula pInicio;

   CLLSL(){
      pInicio = null;
   }

   Celula incluiInicioLLSL(Object x){
      Celula pNovo = new Celula();
      pNovo.info = x;
      pNovo.prox = pInicio;

      return pNovo;
   }

   Object excluiInicioLLSL(){
      if(pInicio == null) return null;
      Object x = pInicio.info;
      Celula pAux = pInicio;
      pInicio = pInicio.prox;
      pAux = null;
      return x;
   }

   Object consultaLLSL(Object x){
      Celula pAux = pInicio;
      while(pAux != null && pAux.info != x)
         pAux = pAux.prox;
      return pAux;
   }
   
   int tamanhoDaLLSL(){
      Celula pAux = pInicio;
      int n = 0;
      while(pAux != null){
         pAux = pAux.prox;
         n++;
      }
      return n;
   }

   void destroiLLSL(){
      while(pInicio != null){
         Celula pAux = pInicio.prox;
         pInicio = null;
         pInicio = pAux;
      }
   }

   public static void main(String[] args){
      Object infoRetorno;
      Celula inicio;
      CLLSL lista = new CLLSL();
      Celula novaCelula = new Celula();
      inicio = lista.incluiInicioLLSL(novaCelula);
      infoRetorno = lista.excluiInicioLLSL();
   }
}
