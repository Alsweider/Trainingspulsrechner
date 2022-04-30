#include <cstdlib>
#include <iostream>


int main() {

	int programmschleife = 1; // Programmablauf wiederholen oder beenden
	int formelwahl = 0; // Entscheidet zwischen Lagerstroem und Karvonen
	double rp = 0, la = 0, fk = 0, tp = 0, aa = 0; 	// Variablen fuer Lagerstroem-Formel
	double kraftausdauer = static_cast<double>(3) / 4; // Faktor 3/4 fuer Kraftausdauersportarten
	double ausdauer = static_cast<double>(2) / 3; // Faktor 2/3 fuer reine Ausdauersportarten
	double ausdauerart = 0; // Nimmt den Wert von kraftausdauer oder ausdauer an, zur Durchfuehrung der Lagerstroem-Berechnung
	std::string ausdauername = "Leer"; // Wird zur Benennung der Ausdauerkategorie im Lagerstroem-Ergebnis verwendet
	double Kruhepuls = 0, Kmaxpuls = 0, Kfaktor = 0, Ktrain = 0; 	// Variablen fuer Karvonen-Formel
	double maximalpuls = 0, geschlecht = 0, maximalpulsGeschlecht = 0; // Fuer die Berechnung der Maximalpuls-Formeln

		std::cout << "Trainingspulsrechner\n";
		std::cout << "--------------------\n\n";

		while (programmschleife == 1) { // Wiederholen des Programms, solange programmschleife den Wert 1 hat

			std::cout << "Bitte treffen Sie Ihre Wahl:\n\n";
			std::cout << "Trainingspuls nach der Lagerstroem-Formel berechnen [1]\n";
			std::cout << "Trainingspuls nach der Karvonen-Formel berechnen [2]\n";
			std::cout << "Maximalpuls nach Hirofumi Tanaka et al berechnen [3]\n";
			std::cout << "Maximalpuls fuer trainierte Sportler nach Winfried Spanaus berechnen [4]\n\n";
			std::cout << "Ihre Eingabe: ";
			
			//Moechten Sie Ihren Trainingspuls nach der Lagerstroem - Formel(1) oder nach der Karvonen - Formel(2) berechnen ? ";
		std::cin >> formelwahl;

		if (std::cin.fail()) {
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}
		else if (formelwahl < 1 || formelwahl >4) {
			std::cout << "Bitte tippen Sie 1 fuer die Lagerstroem-Formel oder 2 fuer die Karvonen-Formel und bestaetigen Sie Ihre Wahl mit der Eingabetaste.\n";
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
				}
				else if (fk < 1 || fk >5) {
					std::cout << "Die Fitnesskategorie " << fk << " existiert im Rahmen der Lagerstroem-Formel nicht. Bitte versuchen Sie eine Zahl zwischen 1 und 5.";
					std::cerr << "Fehler bei der Eingabe\n";
					
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					std::cin.get();

					return EXIT_FAILURE;
				}
				else if (fk == 1) {
					fk = 0.55;
				}
				else if (fk == 2) {
					fk = 0.6;
				}
				else if (fk == 3) {
					fk = 0.65;
				}
				else if (fk == 4) {
					fk = 0.7;
				}
				else if (fk == 5) {
					fk = 0.75;
				}

				std::cout << "Tippen Sie fuer reines Ausdauertraining (Gehen, Laufen, Schwimmen) die 1. Fuer Kraftausdauer-Sportarten (Rudern oder Radfahren) hingegen bitte die 2: ";
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
				std::cout << "Lagerstroem-Formel: Ruhepuls + (220 - Ausdauersportkategorie * Lebensalter - Ruhepuls) * Fitnesskategorie\n";

				tp = rp + (220 - ausdauerart * la - rp) * fk; // Berechnung nach Dieter Lagerstroem 
				std::cout << "Rechnung: " << rp << " + (220 - " << ausdauerart << " * " << la << " - " << rp << ") * " << fk << " = " << tp << "\n\n";

				std::cout << "Ihre optimale Pulsfrequenz fuer das Langzeitausdauertraining bei " << ausdauername << " betraegt: \n" << tp << " Schlaege pro Minute\n\n";
				std::cout << "\n--------------------------------\n\n";

				std::cout << "Moechten Sie eine neue Berechnung durchfuehren? [1] Ja, [0] Nein: ";
				std::cin >> programmschleife;
				std::cout << '\n';

				if (std::cin.fail()) {
					std::cerr << "Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}

			}
		
		else if (formelwahl == 2) { // Ende Lagerstroem-Berechnung, Anfang Karvonen-Berechnung

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
			std::cout << "Karvonen-Formel: Optimale Herzfrequenz = Ruhepuls + (Maximale Herzfrequenz - Ruhepuls) * Intensitaets-Faktor\n";
			Ktrain = Kruhepuls + (Kmaxpuls - Kruhepuls) * Kfaktor;
			std::cout << "Rechnung: " << Kruhepuls << " + (" << Kmaxpuls << " - " << Kruhepuls << ") * " << Kfaktor << " = " << Ktrain << "\n\n";
			std::cout << "Ihre optimale Trainings-Herzfrequenz nach der Karvonen-Formel betraegt: " << Ktrain << " Schlaege pro Minute\n\n";
			std::cout << "--------------------------------\n\n";

			std::cout << "Moechten Sie eine neue Berechnung durchfuehren? [1] Ja, [0] Nein: ";
			std::cin >> programmschleife;
			std::cout << '\n';

			if (std::cin.fail()) {
				std::cerr << "Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}
}
		else if (formelwahl == 3) {
		std::cout << "\nBitte geben Sie Ihr Lebensalter in Jahren ein: ";
		std::cin >> la;

		if (std::cin.fail()) {
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}

		std::cout << "\nTanaka-Formel: Maximalpuls = 208 - 0,7 * Lebensalter\n";
		maximalpuls = 208 - (0.7 * la);
		std::cout << "Rechnung: 208 - 0,7 * " << la << " = " << maximalpuls << "\n\n";
		std::cout << "Ihr theoretischer Maximalpuls nach der Formel von Hirofumi Tanaka betraegt: " << maximalpuls << " Schlaege pro Minute\n";
		
		std::cout << "\nMoechten Sie eine neue Berechnung durchfuehren? [1] Ja, [0] Nein: ";
		std::cin >> programmschleife;
		std::cout << '\n';

		if (std::cin.fail()) {
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}

		}


		else if (formelwahl == 4) {
			std::cout << "\nBitte geben Sie Ihr Lebensalter in Jahren ein: ";
			std::cin >> la;

			if (std::cin.fail()) {
				std::cerr << "Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}

			std::cout << "Bitte geben Sie nun Ihr Geschlecht ein. maennlich [1] / weiblich [0]: ";
			std::cin >> geschlecht;

			if (std::cin.fail()) {
				std::cerr << "Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}

			if (geschlecht < 0 || geschlecht > 1){
				std::cout << "Ungueltige Eingabe. Bitte waehlen Sie die 1 fuer maennlich oder die 0 fuer weiblich.\n";
				std::cerr << "Fehler bei der Eingabe\n";
			}
			else if (geschlecht == 1) {
				geschlecht = 0.9; 
				maximalpulsGeschlecht = 223;
				std::cout << "\nSpanaus-Formel (Maenner): Maximalpuls = 223 - 0,9 * Lebensalter\n";

			}
			else if (geschlecht == 0) {
				geschlecht = 1.0;
				maximalpulsGeschlecht = 226;
				std::cout << "\nSpanaus-Formel (Frauen): Maximalpuls = 226 - 1,0 * Lebensalter\n";

		}

			std::cout << "Rechnung: Maximalpuls = " << maximalpulsGeschlecht << " - " << geschlecht << " * " << la << "\n";
			maximalpuls = maximalpulsGeschlecht - (geschlecht * la);

			std::cout << "Ihr theoretischer Maximalpuls nach der Formel von Winfried Spanaus fuer trainierte Sportler betraegt: " << maximalpuls << " Schlaege pro Minute\n";



		
		std::cout << "\nMoechten Sie eine neue Berechnung durchfuehren? [1] Ja, [0] Nein: ";
		std::cin >> programmschleife;
		std::cout << '\n';

		if (std::cin.fail()) {
			std::cerr << "Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		
		}
}
		
}  // Programmschleife Ende
	
	return EXIT_SUCCESS;
}
