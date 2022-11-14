package hr.fer.oop.lab4.prob1;

/**
 * Enumeration Formation is used to describe certain formations in football.
 * <p>Example, F422 means the formation is 4-4-2: one goalkeeper, four defenders,
 * four midfielders and two forwards.</p>
 * <p>Each type of formation contains constants that determine the number of
 * goalkeepers, defenders, midfielders and forwards in a formation.</p>
 * 
 * @author dinomario10
 */
public enum Formation {
	F442(4, 4, 2), F352(3, 5, 2), F541(5, 4, 1);
	
	/** Maximum number of goalkeepers */
	public final int MAX_GKS = 1;
	/** Maximum number of defenders */
	public final int MAX_DFS;
	/** Maximum number of midfielders */
	public final int MAX_MFS;
	/** Maximum number of forwards */
	public final int MAX_FWS;
	
	/**
	 * Constructor for defined formations.
	 * 
	 * @param max_dfs maximum number of defenders
	 * @param max_mfs maximum number of midfielders
	 * @param max_fws maximum number of forwards
	 */
	Formation(int max_dfs, int max_mfs, int max_fws) {
		MAX_DFS = max_dfs;
		MAX_MFS = max_mfs;
		MAX_FWS = max_fws;
	}
}