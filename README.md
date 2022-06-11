===MAGAZYN CZESCI ELEKTRONICZNYCH===

Program ten jest symulatorem magazynu czesci elektronicznych. Obsluguje on 5 rodzajow czesci elektronicznych:
    - rezystor,
    - kondensator,
    - cewka (dlawik),
    - tranzystor,
    - uklad scalony.
Funkcjonalnosc aplikacji obejmuje:
    - dodawanie i pobieranie komponentow z magazynu,
    - wyswietlenie bazy danych producentow, dodawanie nowych oraz modyfikacja lub usuniecie obecnie istniejacych producentow z bazy danych
    - automatyczna aktualizacje listy producentow o nowych, podanych przy dodawaniu komponentow
    - eksport danych do pliku tekstowego wskazanego przez uzytkownika
Program wczytuje swoj stan i zapisuje go kazdorazowo przy, odpowiednio, uruchamianiu i konczeniu programu.

Pliki binarne programu znajduja sie w folderach "bin/{system}-{konfiguracja}-x86_64".

Program po uruchomieniu daje uzytkownikowi mozliwosc wyboru sposrod jednej z opcji podanej w funkcjonalnosci aplikacji. Wejscie nalezy podac w postaci liczby calkowitej odpowiadajacej zadanej opcji. (Program obsluguje wartosc domyslna przy pustym wejsciu - w tym wypadku jest to wybranie opcji 0, odpowiadajacej cofaniu sie w drzewie menu/wyjsciu z programu). Wszelkie wejscia jednostek SI nalezy podawac w postaci liczbamnoznik, np. 10k, 10, 10p (lista mnoznikow znajduje sie w pliku mnozniki.info).
    - Wybranie opcji dodania lub pobrania komponentu prosi uzytkownika o podanie typu komponentu, a nastepnie prosi o dodatkowe parametry. W przypadku checi pominiecia konkretnego parametru mozna to zrobic, zostawiajac puste wejscie. Na koncu procedury komponent zostanie dodany do magazynu badz, w wypadku checi pobrania, zostanie sprawdzone, czy istnieje taki komponent (pominiecie parametru przy szukaniu komponentu jest uznawane za dopasowanie do kazdego parametru)
    - Wybranie opcji menu producentow stawia uzytkownika przed wyborem wyswietlenia listy producentow, dodania nowego, zmiany danych obecnie istniejacego lub usuniecia wybranego z bazy. Przy ostatnich dwoch opcjach nalezy podac nazwe zadanego producenta, ktorego uzytkownik chce zmodyfikowac/usunac
    - Wybranie opcji eksportu daje uzytkownikowi wybor miedzy eksportem danych magazynu lub bazy danych producentow. Po wybraniu opcji uzytkownik zostanie poproszony o podanie nazwy pliku, do ktorego pragnie zapisac dane. Pliki zapisywane sa w folderze "component_storage/io".
    -Wybranie opcji zakonczenia programu konczy go

Program zapisuje swoje dane do plikow storage.csv i manufacturer.csv, znajdujacych sie w folderze component_storage/io.

W folderze proj_scripts znajduja sie skrypty generujace pliki projektu dla Visual Studio 2022 i Makefile. W tym celu uzywany jest program premake5, znajdujacy sie w folderze vendor. 
