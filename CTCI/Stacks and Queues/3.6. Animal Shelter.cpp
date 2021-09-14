enum Type {
    NONE = 0,
    CAT  = 1,
    DOG  = 2,
};

class Animal {
public:
    int  arrival;
    int  value;
    Type type;

    Animal(int value, Type type)
        : value(value)
        , type(type) {}

};

class AnimalShelter {
private:
    queue<Animal> cats;
    queue<Animal> dogs;
    int timestamp;

public:
    AnimalShelter() {
        timestamp = 0;
    }

    void enqueue(Animal animal) {
        animal.arrival = ++timestamp;

        switch (animal.type) {
            case CAT: {
                cats.push(animal);
            } break;

            case DOG: {
                dogs.push(animal);
            } break;

            default: break;
        }
    }

    Animal dequeCat(){
        Animal result = cats.front();
        cats.pop();
        return result;
    }

    Animal dequeDog(){
        Animal result = dogs.front();
        dogs.pop();
        return result;
    }

    Animal dequeAny() {
        int dogArrival = dogs.front().arrival;
        int catArrival = cats.front().arrival;

        if (dogArrival > 0 && dogArrival < catArrival) {
            return dequeDog();
        } else {
            return dequeCat();
        }
    }

};

void printTestResult(int testNum, int actual, int expected) {
    if (actual == expected) {
        cout << "Test #" << testNum << " " << "Passed" << endl;
    } else {
        cout << "Test #" << testNum << " " << "Failed, Expected: " << expected << ", But was: " << actual << endl;
    }
}

int main() {
    AnimalShelter shelter;

    shelter.enqueue(Animal(5 , CAT));
    shelter.enqueue(Animal(1,  DOG));
    shelter.enqueue(Animal(20, DOG));
    shelter.enqueue(Animal(17, DOG));
    shelter.enqueue(Animal(22, CAT));
    shelter.enqueue(Animal(3,  CAT));

    printTestResult(1, shelter.dequeDog().value, 1);
    printTestResult(2, shelter.dequeDog().value, 20);
    printTestResult(3, shelter.dequeCat().value, 5);
    printTestResult(4, shelter.dequeAny().value, 17);
    printTestResult(5, shelter.dequeAny().value, 22);
    printTestResult(6, shelter.dequeCat().value, 3);

    shelter.enqueue(Animal(1, CAT));
    shelter.enqueue(Animal(2, DOG));
    shelter.enqueue(Animal(3, DOG));
    shelter.enqueue(Animal(4, CAT));

    printTestResult(7,  shelter.dequeAny().value, 1);
    printTestResult(8,  shelter.dequeAny().value, 2);
    printTestResult(9,  shelter.dequeAny().value, 3);
    printTestResult(10, shelter.dequeAny().value, 4);

    return 0;
}