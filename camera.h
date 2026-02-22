auto aspect_ratio = 16.0 / 9.0;
int width = 400;

int height = (width / aspect_ratio < 1) ? 1 : int(width / aspect_ratio);

auto viewport_height = 2.0;
auto viewport_width = viewport_height * (double(width)/height);