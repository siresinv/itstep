	// цемепюжхъ яксвюимшу бшярпекнб
	/*for (int i = 1; i < 10; i++) {
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;

			std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			shotResult = doShot(field1, randLetter, randDigit);
		} while (shotResult == shotRepeat);
		if (shotResult == shotHit) {
			std::cout << scanShipAfterHit(field1, randLetter, randDigit);
		}
		
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;

			std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			shotResult = doShot(field1, randLetter, randDigit);
		} while (shotResult == shotRepeat);
		if (shotResult == shotHit) {
			std::cout << scanShipAfterHit(field1, randLetter, randDigit);
		}


		showField(field1);
		std::cout << std::endl;
		std::cout << std::endl;

	}	
		*/





////////////////////////////////////////////////////////////////////////////////////////////////


// цемепюжхъ онякеднбюрекэмшу бшярпекнб
shotResultType shotResult;
int	randLetter;
int randDigit;
int shotCounter = 0;
for (int i = 0; i < FIELD_SIZE_Y; i++) {
	for (int j = 0; j < FIELD_SIZE_X; j++) {
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;
			std::cout << ++shotCounter;
			std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			shotResult = doShot(gamersList[0].field, i, j);
		} while (shotResult == shotRepeat);
		if (shotResult == shotHit) {
			isShipKilled(gamersList[0].field, i, j);
			showField(gamersList[0].field);
			std::cout << std::endl;
			std::cout << std::endl;
		}


		/*showField(gamersList[0].field);
		std::cout << std::endl;
		std::cout << std::endl;*/
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////


