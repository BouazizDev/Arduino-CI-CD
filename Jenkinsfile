pipeline {
    agent any

    stages {
        stage('Info') {
            steps {
                echo "Branch: ${env.BRANCH_NAME}"
                echo "Commit: ${env.GIT_COMMIT}"
            }
        }

        stage('Build') {
            steps {
                bat '"C:\\Users\\Amine\\.platformio\\penv\\Scripts\\platformio.exe" run'
            }
        }
        stage('Release (master only)') {
    when {
        branch 'master'
    }
    steps {
        echo "Master branch detected → release build"
        archiveArtifacts artifacts: '.pio/build/**', fingerprint: true
    }
}
    }
    
    post {
        success {
            echo "BUILD OK on ${env.BRANCH_NAME}"
        }
        failure {
            echo "BUILD FAILED on ${env.BRANCH_NAME}"
        }
    }
}
