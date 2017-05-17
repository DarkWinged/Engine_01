#version 120

attribute vec2 vertexPostion;

void main() {
	gl_Position.xy = vertexPostion;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
}