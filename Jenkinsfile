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
                script {
                    def version = "v0.0.${env.BUILD_NUMBER}"
                    env.RELEASE_VERSION = version
                    echo "Release version: ${version}"
                }

                archiveArtifacts artifacts: '.pio/build/**', fingerprint: true
            }
        }
    }

    post {
        success {
            script {
                if (env.BRANCH_NAME == 'master') {
                    bat """
                        git tag ${env.RELEASE_VERSION}
                        git push origin ${env.RELEASE_VERSION}
                    """
                }
            }
            echo "BUILD OK on ${env.BRANCH_NAME}"
        }

        failure {
            echo "BUILD FAILED on ${env.BRANCH_NAME}"
        }
    }
}
