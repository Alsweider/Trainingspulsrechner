#include <cstdlib>
#include <iostream>
#include <Windows.h>
// #include <locale.h> // Für deutsche Lokalisierung, aktuell nicht benötigt 
 

int main() {

	// std::locale::global(std::locale("de_DE.UTF-8")); // Für deutsche Lokalisierung, aktuell nicht benötigt 
	SetConsoleOutputCP(CP_UTF8); // Konsolenausgabe auf UTF-8 umstellen zur Darstellung von Umlauten

	int programmschleife = 1; // Programmablauf wiederholen oder beenden
	int formelwahl = 0; // Entscheidet zwischen Lagerstrøm und Karvonen
	double rp = 0, la = 0, fk = 0, tp = 0, aa = 0; 	// Variablen für Lagerstrøm-Formel
	double kraftausdauer = static_cast<double>(3) / 4; // Faktor 3/4 für Kraftausdauersportarten
	double ausdauer = static_cast<double>(2) / 3; // Faktor 2/3 für reine Ausdauersportarten
	double ausdauerart = 0; // Nimmt den Wert von kraftausdauer oder ausdauer an, zur Durchfuehrung der Lagerstrøm-Berechnung
	std::string ausdauername = "Leer"; // Wird zur Benennung der Ausdauerkategorie im Lagerstrøm-Ergebnis verwendet
	double Kruhepuls = 0, Kmaxpuls = 0, Kfaktor = 0, Ktrain = 0; 	// Variablen für Karvonen-Formel
	double maximalpuls = 0, geschlecht = 0, maximalpulsGeschlecht = 0; // für die Berechnung der Maximalpuls-Formeln

		std::cout << u8"Trainingspulsrechner\n";
		std::cout << u8"--------------------\n\n";

		while (programmschleife == 1) { // Wiederholen des Programms, solange programmschleife den Wert 1 hat

			std::cout << u8"Bitte treffen Sie Ihre Wahl:\n\n";
			std::cout << u8"Trainingspuls nach der Lagerstrøm-Formel berechnen [1]\n";
			std::cout << u8"Trainingspuls nach der Karvonen-Formel berechnen [2]\n";
			std::cout << u8"Maximalpuls nach Hirofumi Tanaka et al berechnen [3]\n";
			std::cout << u8"Maximalpuls für trainierte Sportler nach Winfried Spanaus berechnen [4]\n\n";
			std::cout << u8"Ihre Eingabe: ";
			
		std::cin >> formelwahl;

		if (std::cin.fail()) {
			std::cerr << u8"Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}
		else if (formelwahl < 1 || formelwahl > 4) {
			std::cout << u8"Bitte geben Sie eine Zahl von 1 bis 4 ein.\n";
			std::cerr << u8"Fehler bei der Eingabe\n\n";

		}

		// Anfang der Lagerstrøm-Berechnung:

		else if (formelwahl == 1) { 

				std::cout << u8"\nBitte geben Sie Ihren Ruhepuls ein: ";
				std::cin >> rp;
				if (std::cin.fail()) {
					std::cerr << u8"Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}
				std::cout << u8"Bitte geben Sie Ihr Alter in Jahren ein: ";
				std::cin >> la;
				if (std::cin.fail()) {
					std::cerr << u8"Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}
				std::cout << u8"Bitte geben Sie Ihre Fitnesskategorie ein ([1] = völlig untrainiert, [2] = normal sportlich, [3] = Amateursportler, [4] = Leistungssportler, [5] = Hochleistungssportler): "; // Untrainierte trainieren mit niedrigerem Puls.

				std::cin >> fk;
				if (std::cin.fail()) {
					std::cerr << u8"Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}
				else if (fk < 1 || fk >5) {
					std::cout << u8"Die Fitnesskategorie " << fk << u8" existiert im Rahmen der Lagerstrøm-Formel nicht. Bitte versuchen Sie eine Zahl zwischen 1 und 5.";
					std::cerr << u8"Fehler bei der Eingabe\n";
					
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

				std::cout << u8"Tippen Sie für reines Ausdauertraining (Gehen, Laufen, Schwimmen) die [1]. Für Kraftausdauer-Sportarten (Rudern oder Radfahren) hingegen bitte die [2]: ";
				std::cin >> aa;

				if (std::cin.fail()) {
					std::cerr << u8"Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}
				else if (aa < 1 || aa >2) {
					std::cout << u8"Bitte geben Sie die richtige Ausdauerkategorie an ([1] Ausdauer oder [2] Kraftausdauer).\n";
					std::cerr << u8"Fehler bei der Eingabe\n";
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
					std::cout << u8"Bitte geben Sie die richtige Ausdauerkategorie an ([1] Ausdauer oder [2] Kraftausdauer).\n";
					std::cerr << u8"Fehler bei der Eingabe\n";

					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					std::cin.get();
					return EXIT_FAILURE;
				}

				std::cout << u8"\n--------------------------------\n\n";
				std::cout << u8"\nMit diesen Zahlen wird gerechnet:\n\n";
				std::cout << u8"Ruhepuls: " << rp << "\n";
				std::cout << u8"Lebensalter: " << la << "\n";
				std::cout << u8"Fitnesskategorie: " << fk << "\n";
				std::cout << u8"Ausdauersportkategorie: " << ausdauerart << "\n\n";
				std::cout << u8"Lagerstrøm-Formel: Ruhepuls + (220 - Ausdauersportkategorie * Lebensalter - Ruhepuls) * Fitnesskategorie\n";

				tp = rp + (220 - ausdauerart * la - rp) * fk; // Berechnung nach Dieter Lagerstrøm 
				std::cout << u8"Rechnung: " << rp << u8" + (220 - " << ausdauerart << u8" * " << la << " - " << rp << u8") * " << fk << u8" = " << tp << u8"\n\n";

				std::cout << u8"Ihre optimale Pulsfrequenz für das Langzeitausdauertraining bei " << ausdauername << u8" beträgt: \n" << tp << u8" Schläge pro Minute\n\n";
				std::cout << u8"\n--------------------------------\n\n";

				std::cout << u8"Möchten Sie eine neue Berechnung durchführen? [1] Ja, [0] Nein: ";
				std::cin >> programmschleife;
				std::cout << '\n';

				if (std::cin.fail()) {
					std::cerr << u8"Fehler bei der Eingabe\n";
					return EXIT_FAILURE;
				}

			}
		
		else if (formelwahl == 2) { // Ende Lagerstrøm-Berechnung, Anfang Karvonen-Berechnung

			std::cout << u8"\nBitte geben Sie Ihren Ruhepuls ein: ";
			std::cin >> Kruhepuls;

			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}
			else if (Kruhepuls < 0) {
				std::cout << u8"Ein negativer Ruhepuls? Wie haben Sie sich das vorgestellt?\n";
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}

			std::cout << u8"Bitte geben Sie Ihre maximale Herzfrequenz ein: ";
			std::cin >> Kmaxpuls;
			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}
			std::cout << u8"Intensitäts-Faktor: Wählen Sie bitte die [1] für Untrainierte, [2] für extensives Ausdauertraining oder [3] für intensives Ausdauertraining: ";
			std::cin >> Kfaktor;
			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
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
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}

			std::cout << u8"\n--------------------------------\n\n";
			std::cout << u8"\nMit diesen Zahlen wird gerechnet:\n\n";
			std::cout << u8"Ruhepuls: " << Kruhepuls << "\n";
			std::cout << u8"Maximale Herzfrequenz: " << Kmaxpuls << "\n";
			std::cout << u8"Intensitäts-Faktor: " << Kfaktor << "\n\n";
			std::cout << u8"Karvonen-Formel: Optimale Herzfrequenz = Ruhepuls + (Maximale Herzfrequenz - Ruhepuls) * Intensitäts-Faktor\n";
			Ktrain = Kruhepuls + (Kmaxpuls - Kruhepuls) * Kfaktor;
			std::cout << u8"Rechnung: " << Kruhepuls << u8" + (" << Kmaxpuls << u8" - " << Kruhepuls << u8") * " << Kfaktor << u8" = " << Ktrain << u8"\n\n";
			std::cout << u8"Ihre optimale Trainings-Herzfrequenz nach der Karvonen-Formel beträgt: " << Ktrain << u8" Schläge pro Minute\n\n";
			std::cout << u8"--------------------------------\n\n";

			std::cout << u8"Möchten Sie eine neue Berechnung durchführen? [1] Ja, [0] Nein: ";
			std::cin >> programmschleife;
			std::cout << '\n';

			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}
}
		else if (formelwahl == 3) {
		std::cout << u8"\nBitte geben Sie Ihr Lebensalter in Jahren ein: ";
		std::cin >> la;

		if (std::cin.fail()) {
			std::cerr << u8"Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}

		std::cout << u8"\nTanaka-Formel: Maximalpuls = 208 - 0,7 * Lebensalter\n";
		maximalpuls = 208 - (0.7 * la);
		std::cout << u8"Rechnung: 208 - 0,7 * " << la << u8" = " << maximalpuls << "\n\n";
		std::cout << u8"Ihr theoretischer Maximalpuls nach der Formel von Hirofumi Tanaka beträgt: " << maximalpuls << u8" Schläge pro Minute\n";
		
		std::cout << u8"\nMöchten Sie eine neue Berechnung durchführen? [1] Ja, [0] Nein: ";
		std::cin >> programmschleife;
		std::cout << '\n';

		if (std::cin.fail()) {
			std::cerr << u8"Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		}

		}


		else if (formelwahl == 4) {
			std::cout << u8"\nBitte geben Sie Ihr Lebensalter in Jahren ein: ";
			std::cin >> la;

			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			}

			std::cout << u8"Bitte geben Sie nun Ihr Geschlecht ein. männlich [1] / weiblich [0]: ";
			std::cin >> geschlecht;

			if (std::cin.fail()) {
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;
			} 
			else if (geschlecht < 0 || geschlecht > 1){
				std::cout << u8"Ungültige Eingabe. Bitte wählen Sie die [1] für männlich oder die [0] für weiblich.\n";
				std::cerr << u8"Fehler bei der Eingabe\n";
				return EXIT_FAILURE;

			}
			else if (geschlecht == 1) {
				geschlecht = 0.9; 
				maximalpulsGeschlecht = 223;
				std::cout << u8"\nSpanaus-Formel (Männer): Maximalpuls = 223 - 0,9 * Lebensalter\n";

			}
			else if (geschlecht == 0) {
				geschlecht = 1.0;
				maximalpulsGeschlecht = 226;
				std::cout << u8"\nSpanaus-Formel (Frauen): Maximalpuls = 226 - 1,0 * Lebensalter\n";
		}

			std::cout << u8"Rechnung: Maximalpuls = " << maximalpulsGeschlecht << u8" - " << geschlecht << u8" * " << la << u8"\n";
			maximalpuls = maximalpulsGeschlecht - (geschlecht * la);

			std::cout << u8"Ihr theoretischer Maximalpuls nach der Formel von Winfried Spanaus für trainierte Sportler beträgt: " << maximalpuls << u8" Schläge pro Minute\n";

        std::cout << u8"\nMöchten Sie eine neue Berechnung durchführen? [1] Ja, [0] Nein: ";
		std::cin >> programmschleife;
		std::cout << '\n';

		if (std::cin.fail()) {
			std::cerr << u8"Fehler bei der Eingabe\n";
			return EXIT_FAILURE;
		
		}
}
		
}  // Programmschleife Ende
	
	return EXIT_SUCCESS;
}
