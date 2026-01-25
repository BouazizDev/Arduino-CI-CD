pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'dev', url: 'https://github.com/BouazizDev/Arduino-CI-CD.git'
            }
        }

        stage('Build') {
        steps {
        ansiColor('xterm') {
            bat '"C:\\Users\\Amine\\.platformio\\penv\\Scripts\\platformio.exe" run'
            }
        }
    }
   stage('Flash Arduino') {
            when {
                branch 'master'
            }
            steps {
                bat '"C:\\Users\\Amine\\.platformio\\penv\\Scripts\\platformio.exe" run --target upload'
            }
        }
        stage('Archive Artifacts') {
            steps {
                archiveArtifacts artifacts: '.pio\\build\\**', fingerprint: true
            }
        }
    }

    post {
        always {
            echo 'Build finished'
        }
        success {
            echo 'Build successful!'
        }
        failure {
            echo 'Build failed!'
        }
    }
}
