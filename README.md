# EventFlow: Cattle Auction Engine

## 1. Event Concept
This project models a **Cattle Auction** using the EventFlow engine. 
A Cattle Auction is a dynamic live event that requires coordination across multiple distinct areas, such as the main auction tent, medical triage areas, and cattle holding pens. As the event progresses, various alerts (such as escaped bulls, weather emergencies, or capacity warnings) must be broadcasted to the relevant stalls and operational units so they can react dynamically (e.g., locking down pens, preparing defibrillators, or pausing bids). 

## 2. Team Members
* Ashley u25072235
* Thandolwethu u2511446
* Heinrich u25030932

## 3. Build & Run Instructions
The project uses `make` for compilation. It requires a C++11 (or higher) compliant compiler.

**To compile the project:**
```bash
make
```

**To run the simulation:**
```bash
./eventflow
```

**To clean the build files:**
```bash
make clean
```

## 4. Doxygen Instructions
The codebase is documented using Doxygen. 

**To generate the documentation:**
```bash
doxygen Doxyfile
```
This will parse the source code and generate a `docs/` directory.

**To view the documentation:**
Open the generated HTML index file in your preferred web browser:
```bash
# On Linux:
xdg-open docs/html/index.html
# Or simply double-click the file in your file explorer.
```

## 5. Architecture Overview
The Cattle Auction engine is built upon two core Gang of Four (GoF) design patterns:

### Composite Pattern
Used to model the hierarchical part-whole tree structure of the auction.
* **Component:** `EventComponent` defines the interface for all objects in the tree.
* **Composites:** `Auction`, `Tent`, `MedicalArea`, `CattleArea`, and `GeneralArea` act as the branches. They manage child components and recursively forward operations.
* **Leaves:** `CattleStall`, `MedicalStall`, `CardiacStall`, `PulmonaryStall`, `FoodStall`, and `DrinkStall` are the concrete operational units at the bottom of the tree.

### Observer Pattern (Push Model)
Used to establish a one-to-many dependency so that when an emergency or event occurs, all registered units are notified.
* **Subject:** The `Subject` base class manages a list of non-owning pointers to registered `Observer` objects.
* **Observer:** The `Observer` interface defines the reaction hooks (e.g., `escapedBull()`, `capacityAlert()`).
* **Implementation:** We implemented the **Push Model**. When an event like `escapedBull(location, numBulls)` is triggered by a Composite (acting as a Subject), it cascades the event along with the specific data downwards to all attached child observers. The concrete leaf stalls then use polymorphism to react meaningfully to the pushed data based on their internal state.
