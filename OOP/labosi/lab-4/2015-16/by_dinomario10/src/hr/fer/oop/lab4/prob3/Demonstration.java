package hr.fer.oop.lab4.prob3;
 
import java.util.ArrayList;
import java.util.Collection;
 
import hr.fer.oop.lab4.prob1.Coach;
import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob1.Formation;
import hr.fer.oop.lab4.prob1.Misc;
import hr.fer.oop.lab4.prob1.PlayingPosition;
import hr.fer.oop.lab4.prob2.NationalTeam;
 
/**
 * Demonstrates the third problem by using most of the previously created
 * classes, interface IManager that the coach uses to manage the team and a new
 * type of Exception, the UnemployedCoachException.
 * 
 * @author OOP ekipa
 */
public class Demonstration {
 
        public static final String[] PLAYER_NAMES = { "Pilkotesa", "R Vokac", "Smitac", "D Misic", "Dolso", "Narij",
                        "Nastic", "Prekinoski", "N Vokac", "Kuser", "Kobsic" };
        public static final PlayingPosition[] PLAYER_POSITIONS = { PlayingPosition.GK, PlayingPosition.DF,
                        PlayingPosition.DF, PlayingPosition.DF, PlayingPosition.MF, PlayingPosition.MF, PlayingPosition.MF,
                        PlayingPosition.MF, PlayingPosition.MF, PlayingPosition.FW, PlayingPosition.FW };
        public static final int PLAYERS_SIZE = 11;
        public static final int DEF_EMOTION = 80;
        public static final int DEF_SKILL = 85;
 
        public static final String[] OFFERED_PLAYER_NAMES = { "Dotur", "Igor Cvanitovic", "Pranjes", "Cisban", "Zovkovic",
                        "Bibilan" };
        public static final PlayingPosition[] OFFERED_PLAYER_POSITIONS = { PlayingPosition.DF, PlayingPosition.DF,
                        PlayingPosition.MF, PlayingPosition.MF, PlayingPosition.MF, PlayingPosition.FW };
        public static final int OFFERED_PLAYER_SIZE = 6;
 
        public static final String DEF_COUNTRY = "Croatia";
 
        public static void main(String[] args) throws UnemployedCoachException {
 
                FootballPlayer notEligiblePlayer = new FootballPlayer("Butatista", "Argentina", 65, 83, PlayingPosition.FW);
 
                IManager nationalManager = new Coach("Ban Vasten", "Dutch", 66, 70, Formation.F442);
 
                NationalTeam croatia = new NationalTeam("Croatia", Formation.F352, "Croatia");
                nationalManager.setManagingTeam(croatia);
 
                // stvaranje i registracija igraca:
                Collection<FootballPlayer> players = new ArrayList<FootballPlayer>();
                for (int i = 0; i < PLAYERS_SIZE; i++) {
                        players.add(new FootballPlayer(PLAYER_NAMES[i], DEF_COUNTRY, DEF_EMOTION, DEF_SKILL, PLAYER_POSITIONS[i]));
                }
                // dodavanje igrača koji nije dobar za repku
                players.add(notEligiblePlayer);
 
                nationalManager.registerPlayers(players, (FootballPlayer player) -> player.getCountry().equals("Croatia"));
 
                Collection<FootballPlayer> croatianSquad = croatia.getRegisteredPlayers();
                System.out.println("Ispis repke, not eligible player ne bi smio biti na popisu...");
                printPlayerNames(croatianSquad);
 
                nationalManager.pickStartingEleven((FootballPlayer player) -> player.getPlayingSkill() > 0);
                System.out.println("Ispis pocetnih 11:");
                printPlayerNames(croatia.getStartingEleven());
               
 
                System.out.println("Manager forsira svoju 442 formaciju.");
                nationalManager.forceMyFormation();
                nationalManager.pickStartingEleven((FootballPlayer player) -> player.getPlayingSkill() > 0);
                System.out.println(
                                "Sad mu nedostaje jedan branic, broj pocetne jedanaestorice: " + croatia.getStartingEleven().size());
 
                Collection<FootballPlayer> offeredPlayers = new ArrayList<>();
                for (int i = 0; i < OFFERED_PLAYER_SIZE; i++) {
                        offeredPlayers.add(new FootballPlayer(OFFERED_PLAYER_NAMES[i], DEF_COUNTRY, DEF_EMOTION,
                                        Misc.MAX_RANGE, OFFERED_PLAYER_POSITIONS[i]));
                }
                // manager obozava Dotura:
                nationalManager.registerPlayers(offeredPlayers,
                                (FootballPlayer player) -> player.getCountry().equals("Croatia") && player.getName().equals("Dotur"));
                System.out.println("Ispis repke nakon registracije novih igraca, samo Dotur bi se dodatno trebao pojaviti:");
                printPlayerNames(croatia.getRegisteredPlayers());
               
                nationalManager.pickStartingEleven((FootballPlayer player) -> player.getPlayingSkill() > 0);
                Collection<FootballPlayer> startingElevenAfterNewPlayers = croatia.getStartingEleven();
                System.out.println("Ispis prvih "+croatia.getStartingEleven().size()+", (branic Dotur je usao na upraznjeno mjesto u obrani):");
                printPlayerNames(startingElevenAfterNewPlayers);
               
               
        }
 
        public static void printPlayerNames(Collection<FootballPlayer> players) {
                String output = "";
                for (FootballPlayer player : players) {
                        output += player.getName() + "\n";
                }
                System.out.println(output);
        }
 
}