#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces
SDL_Surface *dots = NULL;
SDL_Surface *screen = NULL;

//Events
SDL_Event event;

//Sprite proportions
SDL_Rect clip[4];

SDL_Surface *load_image( std::string filename ){
   SDL_Surface* loadedImage = NULL;
   SDL_Surface* optimizedImage = NULL;
   loadedImage = IMG_Load( filename.c_str() );

   if( loadedImage != NULL ){
      optimizedImage = SDL_DisplayFormat( loadedImage );
      SDL_FreeSurface( loadedImage );

      if( optimizedImage != NULL ){
         SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
      }
   }

   return optimizedImage;
}

   

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){
   //Offsets
   SDL_Rect offset;

   offset.x = x;
   offset.y = y;

   //blit
   SDL_BlitSurface( source, clip, destination, &offset );
}

bool init(){
   if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
      return false;
   }

   screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   if( screen == NULL ){
      return false;
   }

   SDL_WM_SetCaption( "Splitting", NULL );

   return true;
}

bool load_files(){
   dots = load_image( "dots.png" );
   if( dots == NULL ){
      return false;
   }
   return true;
}

void clean_up(){
   SDL_FreeSurface( dots );
   SDL_Quit();
}


int main( int argc, char* args[] ){
   bool quit = false;

   if( init() == false){
      return 1;
   }
   
   //Loading files
   if( load_files() == false ){
      return 1;
   }
   
   //Clip range for the top left 
   clip[ 0 ].x = 0;
   clip[ 0 ].y = 0;
   clip[ 0 ].w = 100;
   clip[ 0 ].h = 100;
   //Clip range for the top right 
   clip[ 1 ].x = 100;
   clip[ 1 ].y = 0;
   clip[ 1 ].w = 100;
   clip[ 1 ].h = 100;
   //Clip range for the bottom left 
   clip[ 2 ].x = 0;
   clip[ 2 ].y = 100;
   clip[ 2 ].w = 100;
   clip[ 2 ].h = 100;
   //Clip range for the bottom right 
   clip[ 3 ].x = 100;
   clip[ 3 ].y = 100;
   clip[ 3 ].w = 100;
   clip[ 3 ].h = 100; 

   SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 

   apply_surface( 0, 0, dots, screen, &clip[ 0 ] ); 
   apply_surface( 540, 0, dots, screen, &clip[ 1 ] ); 
   apply_surface( 0, 380, dots, screen, &clip[ 2 ] ); 
   apply_surface( 540, 380, dots, screen, &clip[ 3 ] ); 

   //Update screen 
   if( SDL_Flip( screen ) == -1 ) { 
      return 1; 
   }  

   while( quit == false ){
      while( SDL_PollEvent( &event )){
         if( event.type == SDL_QUIT ){
            quit = true;
         }
      }
   }

   clean_up();

   return 0;
}
