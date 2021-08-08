//*****************************************
//* This is a project made by Hadar Engel *
//*****************************************


#include <stdlib.h>
#include "Deck.h"

Dadu::Deck::deck_exception : public std::exceptions{
		Deck::deck_exception() = default;
		virtual ~Deck::deck_exception() = default;
		
		virtual const char* what() const noexcept{
		return "Error: deck exception occured\n";
		}
	};
	Dadu::Deck::invalid_argument : public deck_exception{
		Deck::invalid_argument() = default;
		~Deck::invalid_argument() = default;
		
		const char* what() const noexcept{
		return "Error: invalid argument\n";
		}
	};
	
	Dadu::Deck::deck_empty : public deck_exception{
		Deck::empty_deck() = default;
		~Deck::empty_deck() = default;
		
		const char* what() const noexcept{
			return "Error: deck is empty\n";
		}
	};
	
	Dadu::Deck::deck_full : public deck_exception{
		Deck::empty_deck() = default;
		~Deck::empty_deck() = default;
		
		const char* what() const noexcept{
			return "Error: deck is full\n";
		}
	};
	
	Dadu::Deck::missing_array : public deck_exception{
		Deck::missing_array() = default;
		~Deck::missing_array() = default;
		
		const char* what() const noexcept{
		return "Error: array pointer is missing\n";
		}
	};
	
	
	
	Dadu::Deck::Deck(int deck_size_t){
		//save deck_size
		if(array_size <= 0 ){
			throw Dadu::Deck::invalid_argument();
			return;
		}
		deck_size = deck_size_t;
		
		//allocate deck memory
		current_size = deck_size_t;
		deck_arr = deck_inits = deck_validate = nullptr;
		deck_arr = new int[deck_size_t];
		deck_inits = new int[deck_size_t];
		deck_validate = new int[deck_size_t];
		if(deck_arr == nullptr || deck_inits == nullptr || deck_validate == nullptr){
			throw std::bad_alloc();
			return;
		}
		validate_size = 0;
	}
	
	Dadu::Deck::Deck(Deck& deck_t){
		//save array info
		if(deck_t.arr_size <= 0){
			throw Dadu::Deck::invalid_argument();
			return;
		}
		deck_size = deck_t.deck_size;
		
		//allocate deck memory
		current_size = deck_t.current_size;
		deck_arr = deck_inits = deck_validate = nullptr;
		deck_arr = new int[deck_size];
		deck_inits = new int[deck_size];
		deck_validate = new int[deck_size];
		if(deck_arr == nullptr || deck_inits == nullptr || deck_validate == nullptr){
			throw std::bad_alloc();
			return;
		}
		for(int i = 0 ; i < deck_size ; i++){
			deck_arr[i] = deck_t.deck_arr[i];
			deck_inits[i] = deck_t.deck_inits[i];
			deck_validate[i] = deck_t.deck_validate[i];
		}
		validate_size = deck_t.validate_size;
	}
	
	Dadu::Deck::~Deck(){
		if(deck_arr != nullptr){
			delete[] deck_arr;
		}
		if(deck_inits != nullptr){
			delete[] deck_inits;
		}
		if(deck_validate != nullptr){
			delete[] deck_validate;
		}
	}
	
	Deck& Dadu::Deck::operator=(const Deck& deck_t){
		//save array info
		if(deck_t.arr_size <= 0){
			throw Dadu::Deck::invalid_argument();
			return;
		}
		deck_size = deck_t.deck_size;
		
		//allocate deck memory
		current_size = deck_t.current_size;
		deck_arr = deck_inits = deck_validate = nullptr;
		int* deck_arr_tmp = new int[deck_size];
		int* deck_inits_tmp = new int[deck_size];
		int* deck_validate_tmp = new int[deck_size];
		if(deck_arr == nullptr || deck_inits == nullptr || deck_validate == nullptr){
			throw std::bad_alloc();
			return;
		}
		for(int i = 0 ; i < deck_size ; i++){
			deck_arr_tmp[i] = deck_t.deck_arr[i];
			deck_inits_tmp[i] = deck_t.deck_inits[i];
			deck_validate_tmp[i] = deck_t.deck_validate[i];
		}
		if(deck_arr != nullptr){
			delete[] deck_arr;
		}
		deck_arr = deck_arr_tmp;
		if(deck_inits != nullptr){
			delete[] deck_inits;
		}
		deck_inits = deck_inits_tmp;
		if(deck_validate != nullptr){
			delete[] deck_validate;
		}
		deck_validate = deck_validate_tmp;
		
		validate_size = deck_t.validate_size;
		
		return *this;
	}
	
	int Dadu::Deck::pullIndex(){
		//check deck is not empty
		if(current_size <= 0){
			throw Dadu::Deck::deck_empty();
			return -1;
		}
		
		int index = std::rand() % current_size;
		int ret_value = this.getValue(index);
		this.setValue(index , this.getValue(--deck_size));
		
		return ret_value;
	}
	
	
	void Dadu::Deck::pushIndex(int index){
		//check index is in array range 
		if(deck_size <= index || index < 0){
			throw Dadu::Deck::invalid_argument();
			return;
		}
		
		//check deck is not full
		if(deck_size <= current_size){
			throw Dadu::Deck::deck_full();
			return;
		}
		
		this.setValue(current_size++ , index);
	}
	
	int Dadu::Deck::getDeckSize(){
		return this.deck_size;
	}
	
	int Dadu::Deck::getCurrentSize(){
		return this.current_size;
	}
	
	void Dadu::Deck::resetDeck(){
		this.current_size = this.deck_size;
		this.validate_size = 0;
	}
	void Dadu::Deck::emptyDeck(){
		this.current_size = 0;
		this.validate_size = 0;
	}
	
	int Dadu::Deck::getValue(int index){
		if(index < 0 || index >= this.deck_size){
			throw Dadu::Deck::invalid_argument();
			return -1;
		}
		
		if(this.deck_inits[index] >= 0 && this.deck_inits[index] < this.validate_size && this.deck_validate[deck_inits[index]] == index){
			return this.deck_arr[index];
		}
		else{
			this.deck_inits[index] = this.validate_size;
			this.deck_validate[this.validate_size++] = index;
			return index;
		}
	}
	
	void Dadu::Desk::setValue(int index , int value){
		if(index < 0 || index >= this.deck_size){
			throw Dadu::Deck::invalid_argument();
			return;
		}
		
		if(this.deck_inits[index] < 0 || this.deck_inits[index] >= this.validate_size || this.deck_validate[deck_inits[index]] != index){
			this.deck_inits[index] = this.validate_size;
			this.deck_validate[this.validate_size++] = index;
		}
		this.deck_arr[index] = value;
	}
	