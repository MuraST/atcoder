#pragma once

template <typename T>
struct Sum2D {
    int H, W;
    bool init;
    vector<vector<T>> data;
    vector<vector<T>> diff;
    vector<vector<T>> csum;

    Sum2D(int H, int W) : H(H), W(W), init(false),
                          data(H, vector<T>(W, 0)),
                          diff(H + 1, vector<T>(W + 1, 0)),
                          csum(H + 1, vector<T>(W + 1, 0)) {}

    void add_rect(int sy, int sx, int ty, int tx, T v) {
        // [sy,ty) [sx,tx)
        assert(0 <= sy && sy <= ty && ty <= H);
        assert(0 <= sx && sx <= tx && tx <= W);

        diff[sy][sx] += v;
        diff[sy][tx] -= v;
        diff[ty][sx] -= v;
        diff[ty][tx] += v;

        init = false;
    }

    void set(int y, int x, T v) noexcept {
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);

        data[y][x] = v;

        init = false;
    }

    void build() noexcept {
        init = true;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                T v = diff[i][j];
                if (i) v += diff[i - 1][j];
                if (j) v += diff[i][j - 1];
                if (i && j) v -= diff[i - 1][j - 1];
                diff[i][j] = v;
                data[i][j] += v;
            }
        }

        for (int i = 0; i <= H; i++){
            fill(diff[i].begin(), diff[i].end(), 0);
            fill(csum[i].begin(), csum[i].end(), 0);
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                csum[i + 1][j + 1] =
                    data[i][j] + csum[i][j + 1] + csum[i + 1][j] - csum[i][j];
            }
        }
    }


    T get(int y, int x) const {
        assert(init);
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        return data[y][x];
    }

    T sum(int sy, int sx, int ty, int tx) const {
        assert(init);
        assert(0 <= sy && sy <= ty && ty <= H);
        assert(0 <= sx && sx <= tx && tx <= W);

        return csum[ty][tx] - csum[sy][tx] - csum[ty][sx] + csum[sy][sx];
    }

    void reset() {
        for (int i = 0; i < H; i++) fill(data[i].begin(), data[i].end(), 0);
        for (int i = 0; i <= H; i++) fill(diff[i].begin(), diff[i].end(), 0);
        for (int i = 0; i <= H; i++) fill(csum[i].begin(), csum[i].end(), 0);
        build();
    }
};