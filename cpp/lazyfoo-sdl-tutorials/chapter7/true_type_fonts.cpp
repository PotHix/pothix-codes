#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

//Now comes the font
TTF_Font *font = NULL;

SDL_Color textColor = {255, 255, 255 };

bool init(){
   if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
      return false;
   }

   screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   if ( screen == NULL ){
      return false;
   }

   if( TTF_Init() == -1 ){
      return false;
   }

   SDL_WM_SetCaption( "TTF Test", NULL );
    return true;
}

SDL_Surface *load_image( std::string filename ){
   SDL_Surface* loadedImage = NULL;
   SDL_Surface* optimizedImage = NULL;
   loadedImage = IMG_Load( filename.c_str() );

   if( loadedImage != NULL){
      optimizedImage = SDL_DisplayFormat( loadedImage );
      SDL_FreeSurface( loadedImage );

      if( optimizedImage != NULL ){
         SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
      }
   }

   return optimizedImage;
}

bool load_files(){
   background = load_image( "background.png" );
   font = TTF_OpenFont( "lazy.ttf", 28 );

   if ( background == NULL ){
      return false;
   }

   return true;
}

void clean_up(){
   SDL_FreeSurface( background );
   SDL_FreeSurface( message );

   TTF_CloseFont( font );
   TTF_Quit();
   SDL_Quit;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){
   SDL_Rect offset;
   offset.x = x;
   offset.y = y;
   SDL_BlitSurface( source, NULL, destination, &offset );
   offset.x = x;
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

   message = TTF_RenderText_Solid( font, "The quick brown fox jumps over the lazy dog", textColor );
   if( message == NULL ){
      return 1;
   }

   apply_surface( 0, 0, background, screen );
   apply_surface( 0, 150, message, screen );

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
