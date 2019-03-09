import java.util.Vector;

class Set {
    Vector<Integer> dane;

    private void check(Vector<Integer> data) {
        for (int i = 0; i < dane.size(); i++) {
            for (int j = 0; j < dane.size(); j++) {
                if (i != j) {
                    if (dane.elementAt(i).equals(dane.elementAt(j))) {
                        dane.removeElementAt(j);
                    }
                }
            }
        }
    }

    // usowanie powtorzen w secie
    public Set(Vector<Integer> data) {
        this.dane = new Vector<>(data);
        check(this.dane);
    }

    // dodawanie el
    public void Add(int el) {
        dane.add(el);
        check(this.dane);
    }

    // usowanie el
    public void Remove(int el) {
        dane.removeElement(el);
    }

    // suma
    public Vector<Integer> Suma(Set B) {
        Vector<Integer> tmp = new Vector<>(this.dane);
        Vector<Integer> suma = new Vector<>();
        this.dane.addAll(B.dane);
        check(this.dane);

        suma = new Vector<>(this.dane);
        this.dane = new Vector<>(tmp);

        return suma;
    }

    // iloczyn
    public Vector<Integer> Iloczyn(Set B) {
        Vector<Integer> tmp = new Vector<>(this.dane);
        Vector<Integer> iloczyn = new Vector<>();
        this.dane.addAll(B.dane);

        for (int i = 0; i < dane.size(); i++) {
            for (int j = 0; j < dane.size(); j++) {
                if (i != j) {
                    if (dane.elementAt(i).equals(dane.elementAt(j))) {
                        iloczyn.add(dane.get(j));
                        dane.removeElementAt(j);
                    }
                }
            }
        }

        this.dane = new Vector<>(tmp);
        return iloczyn;
    }

    // roznica
    public Vector<Integer> Roznica(Set B) {
        Vector<Integer> tmp = new Vector<>(this.dane);
        Vector<Integer> roznica = new Vector<>(Iloczyn(B));

        for (int i = 0; i < roznica.size(); i++) {
            tmp.removeElement(roznica.get(i));
        }

        return tmp;
    }

    // roznica symetryczna
    public Vector<Integer> RoznicaSym(Set B) {
        Vector<Integer> tmp = new Vector<>(this.dane);
        Set tm = new Set(B.dane);
        B.dane = new Vector<>(Iloczyn(B));
        this.dane = new Vector<>(Suma(tm));

        Vector<Integer> wynik = Roznica(B);
        dane = new Vector<>(tmp);

        return wynik;
    }
}

class St {

    public static void main(String[] args) {
        // tworzymy 2 wektory z danymi
        Vector<Integer> tab = new Vector<>();
        tab.add(1);
        tab.add(2);
        tab.add(3);
        tab.add(4);
        tab.add(5);
        tab.add(3);
        tab.add(2);

        Vector<Integer> Btab = new Vector<>();
        Btab.add(2);
        Btab.add(1);
        Btab.add(9);
        Btab.add(9);
        Btab.add(9);
        Btab.add(4);

        Set A = new Set(tab);
        // dodaje 2 el
        A.Add(5);
        A.Add(8);
        // usowam konkretny el
        A.Remove(8);
        System.out.println("A:");
        A.dane.forEach((n) -> System.out.print(n + " "));

        System.out.println(" ");

        Set B = new Set(Btab);
        System.out.println("B:");
        B.dane.forEach((n) -> System.out.print(n + " "));
        System.out.println(" ");

        // Dodawanie
        System.out.println("Suma:");
        A.Suma(B).forEach((n) -> System.out.print(n + " "));

        // Iloczyn
        System.out.println("\nIloczyn:");
        A.Iloczyn(B).forEach((n) -> System.out.print(n + " "));

        // Roznica
        System.out.println("\nRoznica A\\B:");
        A.Roznica(B).forEach((n) -> System.out.print(n + " "));

        System.out.println("\nRoznica B\\A:");
        B.Roznica(A).forEach((n) -> System.out.print(n + " "));

        // Roznica symetryczna

        System.out.println("\nRoznica Symetryczna:");
        A.RoznicaSym(B).forEach((n) -> System.out.print(n + " "));

        System.out.println(" ");
    }

}