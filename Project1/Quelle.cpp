#include <cstdlib>
#include <iostream>



int main() {

	int formelwahl = 0;
	// Variablen fuer Lagerstroem-Formel:
	double rp = 0, la = 0, fk = 0, tp = 0, aa = 0; 
	double kraftausdauer = static_cast<double>(3) / 4; // Faktor 3/4 fuer Kraftausdauersportarten
	double ausdauer = static_cast<double>(2) / 3; // Faktor 2/3 fuer reine Ausdauersportarten
	// double kraftausdauer = 0.75; // Faktor 3/4 fuer Kraftausdauersportarten
	// double ausdauer = 0.666; // Faktor 2/3 fuer reine Ausdauersportarten
	double ausdauerart = 0;
	std::string ausdauername = "Leer";

	double Kruhepuls = 0, Kmaxpuls = 0, Kfaktor = 0, Ktrain=0; 	// Variablen fuer Karvonen-Formel

	for (int i = 0; i >= 0; i++)
	{

	std::cout << "Trainingspuls berechnen nach Lagerstroem oder Karvonen\n";
	std::cout << "--------------------------------------------------------\n\n";

		

	std::cout << "Moechten Sie Ihren Trainingspuls nach der Lagerstroem-Formel (1) oder nach der Karvonen-Formel (2) berechnen? ";
	std::cin >> formelwahl;

	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	else if (formelwahl<1 || formelwahl >2) {
		std::cout << "Bitte tippen Sie 1 für die Lagerstroem-Formel oder 2 für die Karvonen-Formel und bestaetigen Sie Ihre Wahl mit der Eingabetaste.\n";
		std::cerr << "Fehler bei der Eingabe\n";

	}
	else if (formelwahl == 1) { // Anfang der Lagerstroem-Berechnung

	std::cout << "\nBitte geben Sie Ihren Ruhepuls ein: ";
	std::cin >> rp;
	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	std::cout << "Bitte geben Sie Ihr Alter in Jahren ein: ";
	std::cin >> la;
	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	std::cout << "Bitte geben Sie Ihre Fitnesskategorie ein (1 = voellig untrainiert, 2 = normal sportlich, 3 = Amateursportler, 4 = Leistungssportler, 5 = Hochleistungssportler): "; // Untrainierte trainieren mit niedrigerem Puls.

	std::cin >> fk; 
	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	} else if (fk < 1 || fk >5) {
		std::cout << "Die Fitnesskategorie " << fk << " existiert im Rahmen der Lagerstroem-Formel nicht. Bitte versuchen Sie eine Zahl zwischen 1 und 5.";
		std::cerr << "Fehler bei der Eingabe\n";

		
		/*
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
		*/

		return EXIT_FAILURE;
	} else if(fk==1) {
		fk = 0.55;
	} else if (fk == 2) {
		fk = 0.6;
	} else if (fk == 3) {
		fk = 0.65;
	} else if (fk == 4) {
		fk = 0.7;
	} else if (fk == 5) {
		fk = 0.75;
	} 


	std::cout << "Tippen Sie fuer reines Ausdauertraining (Gehen, Laufen, Schwimmen) die 1.\nFuer Kraftausdauer-Sportarten (Rudern oder Radfahren) hingegen bitte die 2: ";
	std::cin >> aa;

	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	else if (aa < 1 || aa >2) {
		std::cout << "Bitte geben Sie die richtige Ausdauerkategorie an (1 Ausdauer oder 2 Kraftausdauer).\n";
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	else if (aa == 1) {
		ausdauerart = ausdauer;
		ausdauername = "reinen Ausdauersportarten";
	}
	else if (aa == 2) {
		ausdauerart = kraftausdauer;
		ausdauername = "Kraftausdauersportarten";
	}
	else {
		std::cout << "Bitte geben Sie die richtige Ausdauerkategorie an (1 Ausdauer oder 2 Kraftausdauer).\n";
		std::cerr << "Fehler bei der Eingabe\n";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
			return EXIT_FAILURE;
	}

	std::cout << "\n--------------------------------\n\n";
	std::cout << "\nMit diesen Zahlen wird gerechnet:\n\n";
	std::cout << "Ruhepuls: " << rp << "\n";
	std::cout << "Lebensalter: " << la << "\n";
	std::cout << "Fitnesskategorie: " << fk << "\n";
	std::cout << "Ausdauersportkategorie: " << ausdauerart << "\n\n";
	std::cout << "Lagerstroem-Formel: Ruhepuls + (220 - Ausdauersportkategorie * Lebensalter - Ruhepuls) * Fitnesskategorie\n\n";

	tp = rp + (220 - ausdauerart * la - rp) * fk; // Berechnung nach Dieter Lagerstroem 

	
	std::cout << "Ihre optimale Pulsfrequenz fuer das Langzeitausdauertraining bei " << ausdauername << " betraegt: \n" << tp << " Schlaege pro Minute\n\n";
	std::cout << "\n--------------------------------\n\n";
	
	std::cout << "\n\nBitte druecken Sie die Eingabetaste, um die Berechnung zu wiederholen oder schliessen Sie das Konsolenfenster mit dem X-Knopf am oberen Bildschirmrand.\n\n";

	
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	
	
	 
	}
 else if (formelwahl == 2) {
 
	}// Ende Lagerstroem-Berechnung, Anfang Karvonen-Berechnung
	std::cout << "\nBitte geben Sie Ihren Ruhepuls ein: ";
	std::cin >> Kruhepuls;

	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	else if (Kruhepuls < 0) {
		std::cout << "Ein negativer Ruhepuls? Wie haben Sie sich das vorgestellt?\n";
			std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}

	std::cout << "Bitte geben Sie Ihre maximale Herzfrequenz ein (Ergometermessung oder nach Faustregel: 220 - Lebensalter in Jahren): ";
	std::cin >> Kmaxpuls;
	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	std::cout << "Intensitaets-Faktor: Waehlen Sie bitte die 1 fuer Untrainierte, 2 fuer extensives Ausdauertraining oder 3 fuer intensives Ausdauertraining: ";
	std::cin >> Kfaktor;
	if (std::cin.fail()) {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}
	if (Kfaktor == 1) {
		Kfaktor = 0.5;
	}
	else if (Kfaktor == 2) {
		Kfaktor = 0.6;
	}
	else if (Kfaktor == 3) {
		Kfaktor = 0.8;
	}
	else {
		std::cerr << "Fehler bei der Eingabe\n";
		return EXIT_FAILURE;
	}


	    std::cout << "\n--------------------------------\n\n";
	    std::cout << "\nMit diesen Zahlen wird gerechnet:\n\n";
		std::cout << "Ruhepuls: " << Kruhepuls << "\n";
		std::cout << "Maximale Herzfrequenz: " << Kmaxpuls << "\n";
		std::cout << "Intensitaets-Faktor: " << Kfaktor << "\n\n";
		
		std::cout << "Karvonen-Formel: Optimale Herzfrequenz = Ruhepuls + (Maximale Herzfrequenz - Ruhepuls) * Intensitaets-Faktor\n\n";

		Ktrain = Kruhepuls + (Kmaxpuls - Kruhepuls) * Kfaktor;

		std::cout << "Ihre optimale Trainings-Herzfrequenz nach der Karvonen-Formel betraegt: " << Ktrain << " Schlaege pro Minute.\n\n";
		std::cout << "--------------------------------\n\n";


		std::cout << "\n\nBitte druecken Sie die Eingabetaste, um die Berechnung zu wiederholen oder schliessen Sie das Konsolenfenster mit dem X-Knopf am oberen Bildschirmrand.\n\n";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();

	}

	return EXIT_SUCCESS;
}