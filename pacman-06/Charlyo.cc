#include "Player.hh"

using namespace std;


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Charlyo





struct PLAYER_NAME : public Player {


    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
        return new PLAYER_NAME;
    }

    vector<Dir> dirs;
    vector< vector<Cell> >tab;
    queue< pair<int, int> > q;
    vector<int> s;
    vector<int> r;

    /**
     * Attributes for your player can be defined here.
     */     


    /**
     * Play method.
     * 
     * This method will be invoked once per each round.
     * You have to read the board here to place your actions
     * for this round.
     *
     */     
    virtual void play () {
        if (round() == 0) {
            tab = vector< vector<Cell> >(rows(), vector<Cell> (cols()));
            dirs = vector<Dir>(4);
            s = vector<int>(4);
            r = vector<int>(4);
            dirs[0] = Top;
            dirs[1] = Right;
            dirs[2] = Bottom;
            dirs[3] = Left;
            scan(tab, q);
            s[0] = r[3] = -1;
            s[2] = r[1] = 1;
            s[3] = r[0] = s[1] = r[2] = 0;
            cout << distance(pacman(me()).pos.i,pacman(me()).pos.j, tab) << endl;
        }

    }

    void scan (vector< vector<Cell> >& tab, queue< pair<int, int> >& q) {
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0 ; j < cols(); ++j) {
                tab[i][j] = cell(i, j);
                if (tab[i][j].type == Pill or tab[i][j].type == Pill) {
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    inline bool pac_can_move (Pos p, Dir d) {
        CType t = cell(dest(p, d)).type;
        if (t == Wall or t == Gate) return false;
        if (pacman(me()).type == PacMan and cell(dest(p, d)).id != -1) return false;
        return true;
    }


    bool ok(int f, int c, const vector< vector<Cell> >& map) {
        return pos_ok(f, c) and map[f][c].type != Wall;
    }

    int distance(int f0, int c0, const vector< vector<Cell> >& g) {
        int n = g.size();
        int m = g[0].size();
        vector< vector<int> > dst(n, vector<int>(m, -1));
        queue< pair<int, int> > q;
        q.push(make_pair(f0,c0));
        dst[f0][c0] = 0;
        while (not q.empty()) {
            int f = q.front().first;
            int c = q.front().second;
            q.pop();
            if (g[f][c].type == Hammer) return dst[f][c];
            for (int k = 0; k < 4; ++k) {
                int ff = f + s[k];
                int cc = c + r[k];
                if (ok(ff,cc,g) and dst[ff][cc] == -1) {
                    q.push(make_pair(ff,cc));
                    dst[ff][cc] = 1 + dst[f][c];
                    cout << ff << " " << cc << endl;
                }
            }
        }
        return -1;
    }


};

RegisterPlayer(PLAYER_NAME);

