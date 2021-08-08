//*****************************************
//* This is a project made by Hadar Engel *
//*****************************************

#include <exception>

namespace Dadu{

	
	class Deck{
		int deck_size;
		int current_size;
		int* deck_arr;
		int* deck_inits;
		int *deck_validate;
		int validate_size;
			
		public:
			//deck exections:
			class deck_exception;
			class invalid_argument;
			class deck_empty;
			class deck_full;
			class missing_array;

			Deck(const int deck_size_t);
			Deck(const Deck& deck_t);
			~Deck();
			Deck& operator=(Deck& deck_t);
			int pullIndex();
			void pushIndex(int index);
			int getDeckSize();
			int getCurrentSize();
			void resetDeck();
			void emptyDeck();
			



		
		private:
			int getValue(int index);
			void setValue(int index ,int value);
	};
	
	
}