"""
  UVOD U TEORIJU RAČUNARSTVA,
  Ak. God. 2010/2011.
  1. Laboratorijska vježba ($-NKA)

  Definicija konačnog automata zapisana je u tekstualnoj datoteci u slijedećem
formatu:
    1. Red: Skup stanja (odvojena zarezom)
    2. Red: Skup ulaznih znakova (ne sadrži $, odvojeni zarezom)
    3. Red: Prihvatljiva stanja (odvojena zarezom)
    4. Red: Početno stanje
    5. Funkcija prijelaza: trenutnoStanje,ulazniZnak->skupStanja
        * nula ili više redova
        * skupStanja se sastoji od stanja odvojenih zarezima
        * ulazniZnak $ označava 'praznu riječ' iliti 'obavezni prelazak'.

  Stanje se zadaje kao niz velikih i malih slova engleske abecede i dekadskih
znamenaka pri čemu je duljina niza maksimalno 20 znakova.

  Skup ulaznih znakova sastoji se od velikih i malih slova engleske abecede i
dekadskih znamenaka.

  Tekstualna datoteka s ulaznim nizovima može sadržavati više nizova pri čemu se
svaki niz nalazi u zasebnom redu. Za svaki zadani ulazni niz simulator treba
ispisati svaki prijelaz automata te navesti je li konačno stanje automata
prihvatljivo. Ulazni nizovi znakova u ovoj datoteci su proizvoljne ali konačne
duljine.

"""



import sys


###############################################################################
#
# Exceptions.
#
###############################################################################

class InputProcessingError(Exception):
    """Exception raised when a NFSM input processing error occurs."""


###############################################################################
#
# ----
# NFSM
# ----
#
###############################################################################

class NFSM:
    """Non-deterministic finite state machine."""

    def __init__(self, input_chars):
        self.start_state = None
        self.input_chars = input_chars
        self.states = set()
        self.current_states = set()


    def add_state(self, name, acceptable, start):
        state = NFSMState(name, acceptable)
        if state in self.states:
            sys.exit("State '{}' defined multiple times.".format(name))
        self.states.add(state)
        if start:
            if self.start_state is not None:
                sys.exit("Multiple starting states not allowed.")
            self.start_state = state
        return state


    def add_transition(self, source, char, targets):
        if source not in self.states:
            sys.exit("Transition specified from unexpected state '{}'.".format(
                source.name))
        for target in targets:
            if target not in self.states:
                sys.exit("Transition specified to unexpected state '{}'."
                    "".format(target.name))
        if char is not None and char not in self.input_chars:
            sys.exit("Transition from state '{}' specified for an unexpected "
                "input '{}'.".format(source.name, char))
        source.add_transition(char, targets)


    def process_input(self, input):
        print("======================== Processing input: '{}' ==============="
            "=========".format(input))
        accepted = False
        try:
            self._reset()
            for x in input:
                self._new_input_char(x)
                if not self.current_states:
                    break
            for state in self.current_states:
                if state.acceptable:
                    description = "valid"
                    accepted = True
                else:
                    description = "rejected as invalid"
                print("State '{}' {}.".format(state.name, description))
        except InputProcessingError as e:
            print(e)
        print("Input {}.".format("accepted" if accepted else "rejected"))
        print()


    def _new_input_char(self, char):
        print("Processing input character '{}'...".format(char))
        if char not in self.input_chars:
            raise InputProcessingError("Invalid input character - '{}'".format(
                char))
        current_states = self.current_states
        self.current_states = set()
        for state in current_states:
            if not self._try_transition(state, char):
                print("No transition from state '{}'. State rejected as "
                    "invalid.".format(state.name))
        self._process_empty_words()
        self._report_current_state()


    def _process_empty_words(self):
        """
          Triggers as many empty word transitions as possible. Stops when there
        are no more empty word transitions available or when one of the current
        states has been reached or one of the already processed states in this
        empty word transition checking run.

        """
        processed_states = set()
        states_to_process = set(self.current_states)
        while states_to_process:
            for state in states_to_process:
                self._try_transition(state, None)
            processed_states |= states_to_process
            states_to_process = self.current_states - processed_states
        #while loop - prevents the endless loop!

    def _report_current_state(self):
        if self.current_states:
            print("--- Current states: {}".format(", ".join(x.name for x in
                self.current_states)))


    def _report_transition(self, source, target, char):
        if char is None:
            char_description = "empty word"
        else:
            char_description = char
        print("Transition '{}' --({})--> '{}'.".format(source.name,
            char_description, target.name))


    def _reset(self):
        if self.start_state is None:
            raise InputProcessingError("No starting states defined.")
        print("--- Starting state: '{}'".format(self.start_state.name))
        self.current_states = {self.start_state}
        self._process_empty_words()
        self._report_current_state()


    def _try_transition(self, source, char):
        targets = source.transitions.get(char, [])
        for target in targets:
            self._report_transition(source, target, char)
            self.current_states.add(target)
        return bool(targets)


###############################################################################
#
# ---------
# NFSMState
# ---------
#
###############################################################################

class NFSMState:
    """
      Class modeling a single state in a NFSM (non-deterministic finite state
    machine) instance. Its member data should never be modified directly.

    """

    def __init__(self, name, acceptable):
        self.name = name
        self.acceptable = acceptable
        self.transitions = dict()


    def __hash__(self):
        """
          Makes state instances with matching names be treated as equal when
        stored in a hash based container such as a set or as a dictionary key.

        """
        return self.name.__hash__()


    def add_transition(self, char, targets):
        """
          Internal function that should only be called by this state's NFSM
        instance.

        """
        if char in self.transitions:
            if char is None:
                input_description = "empty word input"
            else:
                input_description = "input '{}'".format(char)
            sys.exit("Multiple transitions from state '{}' specified for {}."
                "".format(self.name, input_description))
        self.transitions[char] = targets


###############################################################################
#
# load_nfsm()
# -----------
#
###############################################################################

def load_nfsm(file_name):
    """Creates a NFSM instance based on a read NFSM definition input file."""
    with open(file_name, "rt") as file:
        state_names = _read_states(file)
        input_chars = _read_input_chars(file)
        acceptable_state_names = _read_acceptable_states(file, state_names)
        start_state_name = _read_start_state(file, state_names)
        nfsm = NFSM(input_chars)
        state_map = _add_states(nfsm, state_names, acceptable_state_names,
            start_state_name)
        _read_transitions(file, nfsm, state_map)
    return nfsm


###############################################################################
#
# _add_states()
# -------------
#
###############################################################################

def _add_states(nfsm, state_names, acceptable_state_names, start_state_name):
    """
      Implementation detail for reading the NFSM definition input file. Adds
    NFSM states based on the information read from a NFSM definition input
    file.

    """
    state_map = {}
    for state_name in state_names:
        if state_name in state_map:
            sys.exit("Warning: State '{}' listed multiple times in the NFSM "
                "definition input file.".format(state_name))
        acceptable = state_name in acceptable_state_names
        start = state_name == start_state_name
        state_map[state_name] = nfsm.add_state(state_name, acceptable, start)
    return state_map


###############################################################################
#
# _parse_transition_rule()
# ------------------------
#
###############################################################################

def _parse_transition_rule(input):
    """Implementation detail for reading the NFSM definition input file."""
    split_result = input.split("->", 1)
    if len(split_result) < 2:
        sys.exit("Invalid transition definition '{}'. Missing '->' token."
            "".format(input))
    source_and_char, target_names = split_result

    split_result = source_and_char.split(",", 1)
    if len(split_result) < 2:
        sys.exit("Invalid transition definition '{}'. Could not parse source "
            "state and character.Missing '->' token.".format(input))
    source_name, char = split_result

    char = char.strip()
    target_names = [x.strip() for x in target_names.split(",")]
    return source_name.strip(), None if char == "$" else char, target_names


###############################################################################
#
# _read_acceptable_states()
# -------------------------
#
###############################################################################

def _read_acceptable_states(file, state_names):
    """Implementation detail for reading the NFSM definition input file."""
    acceptable_state_names = _read_strings(file)
    if not acceptable_state_names:
        sys.exit("No acceptable states listed in the NFSM definition input "
            "file.") 	
    for x in acceptable_state_names:
        if x not in state_names:
            sys.exit("Acceptable state '{}' not found among the listed states."
                "".format(x))
    return acceptable_state_names


###############################################################################
#
# _read_input_chars()
# -------------------
#
###############################################################################

def _read_input_chars(file):
    """Implementation detail for reading the NFSM definition input file."""
    input_chars = _read_strings(file)
    if not input_chars:
        sys.exit("No input chars listed in the NFSM definition input file.")
    for x in input_chars:
        if not x:
            sys.exit("Empty input char listed in the NFSM definition input "
                "file.")
        if len(x) > 1:
            sys.exit("Only single characters are allowed as valid input for "
                "our NFSM. Multicharacter string found listed as possible "
                "input in the NFSM definition input file.")
    return input_chars


###############################################################################
#
# _read_start_state()
# -------------------
#
###############################################################################

def _read_start_state(file, state_names):
    """Implementation detail for reading the NFSM definition input file."""
    start_state_names = _read_strings(file)
    if not start_state_names:
        sys.exit("No starting state listed in the NFSM definition input file.")
    if len(start_state_names) > 1:
        sys.exit("Multiple starting states listed in the NFSM definition "
            "input file.")
    start_state_name = start_state_names[0]
    if start_state_name not in state_names:
        sys.exit("Start state '{}' not found among the listed states."
            "".format(start_state_name))
    return start_state_name


###############################################################################
#
# _read_states()
# --------------
#
###############################################################################

def _read_states(file):
    """Implementation detail for reading the NFSM definition input file."""
    state_names = _read_strings(file)
    print(state_names)
    if not state_names:
        sys.exit("No states listed in the NFSM definition input file.")
    return state_names


###############################################################################
#
# _read_strings()
# ---------------
#
###############################################################################

def _read_strings(file):
    """Implementation detail for reading the NFSM definition input file."""
    return [x.strip() for x in file.readline().rstrip().split(",")]


###############################################################################
#
# _read_transitions()
# -------------------
#
###############################################################################

def _read_transitions(file, nfsm, state_map):
    """Implementation detail for reading the NFSM definition input file."""
    for line in file:
        source_name, char, target_names = _parse_transition_rule(line)
        try:
            targets = [state_map[x] for x in target_names]
        except KeyError as e:
            # KeyError exception description string is already quoted.
            sys.exit("Unexpected transition target state {}.".format(e))
        nfsm.add_transition(state_map[source_name], char, targets)


###############################################################################
#
# main()
# ------
#
###############################################################################

if __name__ == "__main__":
    nfsm = load_nfsm("nfsm.txt")
    with open("input.txt", "rt") as file:
        for input in file:
            nfsm.process_input(input.rstrip())
