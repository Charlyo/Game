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
    queue<Dir> way;

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
            dirs[0] = Top;
            dirs[1] = Right;
            dirs[2] = Bottom;
            dirs[3] = Left;
            scan(tab, q);
            way = fake_bfs(tab, q.front());
        }
        if (not way.empty()) {
            move_my_pacman(way.front());
            way.pop();
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

    queue<Dir> fake_bfs(vector< vector<Cell> >& tab, pair<int, int>& p) {
        vector<int> co(4);
        queue<Dir> cua;
        pair<int, int> min(5000, -1);
        Pos aux = pacman(me()).pos;
        while (aux != Pos(p.first, p.second)) {
            min = make_pair(aux.i*aux.i+aux.j*aux.j, -1);
            for (int i = 0; i < 4; ++i) {
                if (i == 0) {
                    if (pac_can_move(aux, dirs[i])) {
                        co[0] = (p.first-aux.i-1)*(p.first-aux.i-1)+(p.second-aux.j)*(p.second-aux.j);
                        cout << "distancia 0  " << co[0] << endl;
                    }
                }
                else if (i == 1) {
                    if (pac_can_move(aux, dirs[i])) {
                        co[1] = (p.first-aux.i)*(p.first-aux.i)+(p.second-aux.j+1)*(p.second-aux.j+1);
                        cout << "distancia 1  " << co[1] << endl;
                    }
                }
                else if (i == 2) {
                    if (pac_can_move(aux, dirs[i])) {
                        co[2] = (p.first-aux.i+1)*(p.first-aux.i+1)+(p.second-aux.j)*(p.second-aux.j);
                        cout << "distancia 2  " << co[2] << endl;
                    }
                }
                else {
                    if (pac_can_move(aux, dirs[i])) {
                        co[3] = (p.first-aux.i)*(p.first-aux.i)+(p.second-aux.j-1)*(p.second-aux.j-1);
                        cout << "distancia 3  " << co[3] << endl;
                    }
                }
                if (min.first > co[i] and pac_can_move(aux, dirs[i])) {
                    min.first = co[i];
                    min.second = i;
                    cout << "entra " << i << endl;
                }
            }
            cout << aux.i << " " << aux.j << endl;
            cua.push(dirs[min.second]);
            aux = dest(aux, dirs[min.second]);
        }
        return cua;
    }
};

RegisterPlayer(PLAYER_NAME);

