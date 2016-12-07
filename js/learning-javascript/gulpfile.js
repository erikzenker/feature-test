const gulp = require('gulp');
const babel = require('gulp-babel')
const eslint = require('gulp-eslint')
// put gulp dependencies here

gulp.task('default', function(){
    // run eslint
    gulp.src(["es6/**/*.js", "public/es6/**/*.js"])
        .pipe(eslint())
        .pipe(eslint.format());
    // translate server code
    gulp.src("es6/**/*.js")
        .pipe(babel())
        .pipe(gulp.dest("dist"));
    // translate client code
    gulp.src("public/es6/**/*.js")
        .pipe(babel())
        .pipe(gulp.dest("public/dist"));
    // put gulp tasks here
});
