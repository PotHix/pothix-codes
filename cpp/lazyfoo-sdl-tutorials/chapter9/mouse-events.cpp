#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

//Surfaces
SDL_Surface *screen = NULL;
SDL_Surface *buttonSheet = NULL;

SDL_Event event;

SDL_Rect clips[ 4 ];

//The button class
class Button{
   private:
      //button attributes
      SDL_Rect box;

      //The part of the button sprite sheet that will be shoun
      SDL_Rect* clip;

   public:
      //Initialize the variables
      Button( int x, int y, int w, int h );

      //Handles events and set the button's sprite region
      void handle_events();

      //shows the button on the screen
      void show();
};

void set_clips(){
   //Clip sprite sheet
   clips[ CLIP_MOUSEOVER ].x = 0;
   clips[ CLIP_MOUSEOVER ].y = 0;
   clips[ CLIP_MOUSEOVER ].w = 320;
   clips[ CLIP_MOUSEOVER ].h = 240;

   clips[ CLIP_MOUSEOUT ].x = 320;
   clips[ CLIP_MOUSEOUT ].y = 0;
   clips[ CLIP_MOUSEOUT ].w = 320;
   clips[ CLIP_MOUSEOUT ].h = 240;

   clips[ CLIP_MOUSEDOWN ].x = 0;
   clips[ CLIP_MOUSEDOWN ].y = 240;
   clips[ CLIP_MOUSEDOWN ].w = 320;
   clips[ CLIP_MOUSEDOWN ].h = 240;

   clips[ CLIP_MOUSEUP ].x = 320;
   clips[ CLIP_MOUSEUP ].y = 240;
   clips[ CLIP_MOUSEUP ].w = 320;
   clips[ CLIP_MOUSEUP ].h = 240;
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

void clean_up(){
   SDL_FreeSurface( buttonSheet );
   SDL_Quit();
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){
   SDL_Rect offset;
   offset.x = x;
   offset.y = y;
   SDL_BlitSurface( source, clip, destination, &offset );
}

Button::Button( int x, int y, int w, int h ){
   //setting the attributs of the button
   box.x = x;
   box.y = y;
   box.w = w;
   box.h = h;

   //set the default sprite
   clip = &clips[ CLIP_MOUSEOUT ];
}

void Button::handle_events(){
   //mouse offsets
   int x=0, y=0;

   //If mouse moved
   if( event.type == SDL_MOUSEMOTION ){
      //Get mouse offsets
      x = event.motion.x;
      y = event.motion.y;

      //If the mouse is over the button
      if( ( x > box.x ) && (x < box.x + box.w) && ( y > box.y) && ( y < box.y + box.h ) ){
	 //set the button sprite
	 clip = &clips[ CLIP_MOUSEOVER ];
      } else {
	 //set the button sprite
	 clip = &clips[ CLIP_MOUSEOUT ];
      }
   }

   //If a mouse button is pressed
   if( event.type == SDL_MOUSEBUTTONDOWN ){
      //if the left mouse button was pressed
      if( event.button.button == SDL_BUTTON_LEFT ){
	 //Get the mouse offsets
	 x = event.button.x;
	 y = event.button.y;

	 //If the mouse is over the button
	 if( ( x > box.x ) && (x < box.x + box.w) && ( y > box.y) && ( y < box.y + box.h ) ){
	    //set the button sprite
	    clip = &clips[ CLIP_MOUSEDOWN ];
	 }
      }
   }

   //If a mouse button is released
   if( event.type == SDL_MOUSEBUTTONUP ){
      //if the left mouse button was released
      if( event.button.button == SDL_BUTTON_LEFT ){
	 //Get the mouse offsets
	 x = event.button.x;
	 y = event.button.y;

	 //If the mouse is over the button
	 if( ( x > box.x ) && (x < box.x + box.w) && ( y > box.y) && ( y < box.y + box.h ) ){
	    //set the button sprite
	    clip = &clips[ CLIP_MOUSEUP ];
	 }
      }
   }
}

void Button::show(){
   //show the button
   apply_surface( box.x, box.y, buttonSheet, screen, clip );
}

bool init(){
   if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
      return false;
   }
   screen = SDL_SetVideoMode(  SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   if( screen == NULL ){
      return false;
   }

   SDL_WM_SetCaption( "Mouse events", NULL );

   return true;
}

int main (int argc, char* args[] ){
   bool quit = false;

   if( init() == false ){
      return 1;
   }

   buttonSheet = load_image("button.png");
   if( buttonSheet == NULL ){
      return 1;
   }

   //Clip the sprite sheet
   set_clips();

   //Make the button
   Button myButton( 170, 120, 320, 240 );

   //While the user hasn't quit
   while( quit == false ){
      //if there's events to handle
      if( SDL_PollEvent( &event ) ){
	 //handle button events
	 myButton.handle_events();

	 if( event.type == SDL_QUIT ){
	    quit = true;
	 }
      }

      //Fill the screen white
      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

      //Show the button
      myButton.show();

      //Update the screen
      if( SDL_Flip( screen ) == -1 ){
	 return 1;
      }
   }

   clean_up();

   return 0;
}
