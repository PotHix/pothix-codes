#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces :)
SDL_Surface *message = NULL;
SDL_Surface *upMessage = NULL;
SDL_Surface *downMessage = NULL;
SDL_Surface *leftMessage = NULL;
SDL_Surface *rightMessage = NULL;

SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

TTF_Font *font = NULL;

SDL_Color textColor = {0, 0, 0 };

bool init(){
   if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
      return false;
   }

   screen = SDL_SetVideoMode(  SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   if ( screen == NULL ){
      return false;
   }

   if( TTF_Init() == -1 ){
      return false;
   }

   SDL_WM_SetCaption( "Key Presses", NULL );

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
   font = TTF_OpenFont( "lazy.ttf", 60 );

   if( background == NULL ){
      return false;
   }

   if( font == NULL ){
      return false;
   }

   return true;
}

void clean_up(){
   SDL_FreeSurface( background );
   SDL_FreeSurface( upMessage );
   SDL_FreeSurface( downMessage );
   SDL_FreeSurface( leftMessage );
   SDL_FreeSurface( rightMessage );

   TTF_CloseFont( font );
   TTF_Quit();
   SDL_Quit();
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){
   SDL_Rect offset;
   offset.x = x;
   offset.y = y;
   SDL_BlitSurface( source, clip, destination, &offset );
}

int main (int argc, char* args[] ){
   bool quit = false;

   if( init() == false ){
      return 1;
   }

   if( load_files() == false ){
      return 1;
   }

   upMessage = TTF_RenderText_Solid( font, "Up key was pressed", textColor );
   downMessage = TTF_RenderText_Solid( font, "Down key was pressed", textColor );
   leftMessage = TTF_RenderText_Solid( font, "Left key was pressed", textColor );
   rightMessage = TTF_RenderText_Solid( font, "Right key was pressed", textColor );


   apply_surface( 0, 0, background, screen );

   while( quit == false ){
      if( SDL_PollEvent( &event )){
	 if( event.type == SDL_KEYDOWN ){
	    switch( event.key.keysym.sym ){
	       case SDLK_UP: message = upMessage; break;
	       case SDLK_DOWN: message = downMessage; break;
	       case SDLK_LEFT: message = leftMessage; break;
	       case SDLK_RIGHT: message = rightMessage; break;
	    }

	 } else if ( event.type == SDL_QUIT ){
	    quit = true;
	 }
      }

      if( message != NULL ){
	 apply_surface( 0, 0, background, screen );
	 apply_surface( ( SCREEN_WIDTH - message->w ) / 2, ( SCREEN_HEIGHT - message->h ) / 2, message, screen );

	 message = NULL;
      }


      if( SDL_Flip( screen ) == -1 ){
	 return 1;
      }
   }

   clean_up();
   return 0;

}
