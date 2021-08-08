/****************************************
 * This is a project made by Hadar Engel *
 *****************************************/

#include <exception>

namespace Dadu{

	
	class Deck{
		int deck_size;
		int current_size;
		int* deck_arr,deck_inits,deck_validate;
		int validate_size;
			
		public:
			Deck(const int deck_size_t);
			Deck(const Deck& deck_t);
			~Deck();
			Deck& operator=(const Deck& deck_t);
			int pullIndex();
			void pushIndex(int index);
			int getDeckSize();
			int getCurrentSize();
			void resetDeck();
			void emptyDeck();
			
		//deck exections:
		class deck_exception : public std::exception;
		class invalid_argument : public deck_exception;
		class deck_empty : public deck_exception;
		class deck_full : public deck_exception;
		class missing_array : public deck_exception;


		
		private:
			int getValue(int index);
			void setValue(int index ,int value);
	};
	
	
}