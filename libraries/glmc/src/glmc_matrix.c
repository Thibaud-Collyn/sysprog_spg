#include <glmc.h>
#include <math.h>

void			glmc_identity(t_mat4 dest)
{
	dest[0] = 1.0;
	dest[1] = 0.0;
	dest[2] = 0.0;
	dest[3] = 0.0;
	dest[4] = 0.0;
	dest[5] = 1.0;
	dest[6] = 0.0;
	dest[7] = 0.0;
	dest[8] = 0.0;
	dest[9] = 0.0;
	dest[10] = 1.0;
	dest[11] = 0.0;
	dest[12] = 0.0;
	dest[13] = 0.0;
	dest[14] = 0.0;
	dest[15] = 1.0;
}

void			glmc_scale(const t_mat4 m, const t_vec3 scale, t_mat4 dest)
{
    dest[0] = m[0] * scale[XX];
    dest[1] = m[1] * scale[XX];
    dest[2] = m[2] * scale[XX];
    dest[3] = m[3] * scale[XX];
    dest[4] = m[4] * scale[YY];
    dest[5] = m[5] * scale[YY];
    dest[6] = m[6] * scale[YY];
    dest[7] = m[7] * scale[YY];
    dest[8] = m[8] * scale[ZZ];
    dest[9] = m[9] * scale[ZZ];
    dest[10] = m[10] * scale[ZZ];
    dest[11] = m[11] * scale[ZZ];
    dest[12] = m[12];
    dest[13] = m[13];
    dest[14] = m[14];
    dest[15] = m[15];
}

void			glmc_rotate(const t_mat4 m, float angle, t_vec3 axis, t_mat4 dest)
{
	float		n[9];
	float		sinus = sinf(angle);
	float		cosinus = cosf(angle);
	float		tang = 1.0f - cosinus;

	glmc_normalize(axis);
	n[0] = axis[XX] * axis[XX] * tang + cosinus;
	n[1] = axis[YY] * axis[XX] * tang + axis[ZZ] * sinus;
	n[2] = axis[ZZ] * axis[XX] * tang - axis[YY] * sinus;
	n[3] = axis[XX] * axis[YY] * tang - axis[ZZ] * sinus;
	n[4] = axis[YY] * axis[YY] * tang + cosinus;
	n[5] = axis[ZZ] * axis[YY] * tang + axis[XX] * sinus;
	n[6] = axis[XX] * axis[ZZ] * tang + axis[YY] * sinus;
	n[7] = axis[YY] * axis[ZZ] * tang - axis[XX] * sinus;
	n[8] = axis[ZZ] * axis[ZZ] * tang + cosinus;
	dest[0] = m[0] * n[0] + m[4] * n[1] + m[8] * n[2];
	dest[1] = m[1] * n[0] + m[5] * n[1] + m[9] * n[2];
	dest[2] = m[2] * n[0] + m[6] * n[1] + m[10] * n[2];
	dest[3] = m[3] * n[0] + m[7] * n[1] + m[11] * n[2];
	dest[4] = m[0] * n[3] + m[4] * n[4] + m[8] * n[5];
	dest[5] = m[1] * n[3] + m[5] * n[4] + m[9] * n[5];
	dest[6] = m[2] * n[3] + m[6] * n[4] + m[10] * n[5];
	dest[7] = m[3] * n[3] + m[7] * n[4] + m[11] * n[5];
	dest[8] = m[0] * n[6] + m[4] * n[7] + m[8] * n[8];
	dest[9] = m[1] * n[6] + m[5] * n[7] + m[9] * n[8];
	dest[10] = m[2] * n[6] + m[6] * n[7] + m[10] * n[8];
	dest[11] = m[3] * n[6] + m[7] * n[7] + m[11] * n[8];
	dest[12] = m[12];
	dest[13] = m[13];
	dest[14] = m[14];
	dest[15] = m[15];
}

void			glmc_translate(const t_mat4 m, const t_vec3 vec, t_mat4 dest)
{
	dest[0] = m[0];
	dest[1] = m[1];
	dest[2] = m[2];
	dest[3] = m[3];
	dest[4] = m[4];
	dest[5] = m[5];
	dest[6] = m[6];
	dest[7] = m[7];
	dest[8] = m[8];
	dest[9] = m[9];
	dest[10] = m[10];
	dest[11] = m[11];
	dest[12] = m[0] * vec[XX] + m[4] * vec[YY] + m[8] * vec[ZZ] + m[12];
	dest[13] = m[1] * vec[XX] + m[5] * vec[YY] + m[9] * vec[ZZ] + m[13];
	dest[14] = m[2] * vec[XX] + m[6] * vec[YY] + m[10] * vec[ZZ] + m[14];
	dest[15] = m[3] * vec[XX] + m[7] * vec[YY] + m[11] * vec[ZZ] + m[15];
}

void            glmc_mat4_multiply(t_mat4 a, t_mat4 b, t_mat4 dest) {
    dest[0] = a[0] * b[0] + a[4] * b[1] + a[8] * b[2] + a[12] * b[3];
    dest[1] = a[1] * b[0] + a[5] * b[1] + a[9] * b[2] + a[13] * b[3];
    dest[2] = a[2] * b[0] + a[6] * b[1] + a[10] * b[2] + a[14] * b[3];
    dest[3] = a[3] * b[0] + a[7] * b[1] + a[11] * b[2] + a[15] * b[3];

    dest[4] = a[0] * b[4] + a[4] * b[5] + a[8] * b[6] + a[12] * b[7];
    dest[5] = a[1] * b[4] + a[5] * b[5] + a[9] * b[6] + a[13] * b[7];
    dest[6] = a[2] * b[4] + a[6] * b[5] + a[10] * b[6] + a[14] * b[7];
    dest[7] = a[3] * b[4] + a[7] * b[5] + a[11] * b[6] + a[15] * b[7];

    dest[8] = a[0] * b[8] + a[4] * b[9] + a[8] * b[10] + a[12] * b[11];
    dest[9] = a[1] * b[8] + a[5] * b[9] + a[9] * b[10] + a[13] * b[11];
    dest[10] = a[2] * b[8] + a[6] * b[9] + a[10] * b[10] + a[14] * b[11];
    dest[11] = a[3] * b[8] + a[7] * b[9] + a[11] * b[10] + a[15] * b[11];

    dest[12] = a[0] * b[12] + a[4] * b[13] + a[8] * b[14] + a[12] * b[15];
    dest[13] = a[1] * b[12] + a[5] * b[13] + a[9] * b[14] + a[13] * b[15];
    dest[14] = a[2] * b[12] + a[6] * b[13] + a[10] * b[14] + a[14] * b[15];
    dest[15] = a[3] * b[12] + a[7] * b[13] + a[11] * b[14] + a[15] * b[15];
}